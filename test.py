import argparse
import collections
import itertools
import json
import os
import re
import subprocess as sp
import sys

DEFAULT_TIME_LIMIT = 2
TEST_RESULT_TYPE = {
    'pass':                'OK ',
    'file_not_found':      " ? ",
    'compile_error':       'CE ',
    'wrong_answer':        'WA ',
    'runtime_error':       'RE ',
    'time_limit_exceed':   'TLE',
    'memory_limit_exceed': 'MLE',
}
MEMORY_LIMIT = 512

COMPILE_OUT = 'a.out'
RUN_OUT = 'b.out'
ERROR_OUT = 'e.out'

CPP_COMPILE_CMD = ['g++', '-O2', '-static', '-o', COMPILE_OUT, '']
RUN_CMD = {
    'cpp': ['/usr/bin/time', '--verbose', './' + COMPILE_OUT],
    'py': ['/usr/bin/time', '--verbose', 'python3', '']
}
COMPARE_CMD = ['diff', '-Z', RUN_OUT, '']
SCRIPT_TEST_CMD = ['python3', '', '', RUN_OUT, '']

FAIL_SCRIPT = 'Test Failed.\n Error Code: {}\n'


class _TestEntry:
    __slots__ = {'setid', 'caseid', 'fin', 'fout', 'rtype', 'time', 'memory'}

    def __init__(self, setid, caseid):
        self.setid = setid
        self.caseid = caseid
        self.fin = self.fout = self.rtype = self.time = self.memory = None
    
    def __lt__(self, other):
        if self.setid != other.setid:
            return self.setid < other.setid
        
        return self.caseid < other.caseid
    
    def __repr__(self):
        rep = {
            'setid': self.setid,
            'caseid': self.caseid,
            'fin': self.fin,
            'fout': self.fout,
            'rtype': self.rtype,
            'time': self.time, 
            'memory': self.memory
        }
        return json.dumps(rep, separators=(',', ':'), indent=2)


def find_test_cases(folder):
    files = os.listdir(folder)
    entry_dict = {}
    for f in files:
        name = f
        if f.endswith('.in'):
            out = False
            f = f[:-3]
        elif f.endswith('.out'):
            out = True
            f = f[:-4]
        else:
            continue
            
        if f in entry_dict:
            if not entry_dict[f].fout:
                entry_dict[f].fout = os.path.join(folder, name)
            else:
                entry_dict[f].fin = os.path.join(folder, name)
        else:
            i = f.find('.')
            f = f[i+1:]

            if '.' in f:
                i = f.find('.')
                setid, caseid = f[:i], f[i+1:]
            elif '-' in f:
                i = f.find('-')
                setid, caseid = f[:i], f[i+1:]
            elif f.startswith('sample'):
                setid, caseid = 'sample', f[6:]
                if not caseid:
                    caseid = 1
            elif f.startswith('samp'):
                setid, caseid = 'sample', f[4:]
                if not caseid:
                    caseid = 1
            elif re.match(r'(\d+)([a-z])', f):
                setid, caseid = f[:-1], ord(f[-1]) - ord('a') + 1
            else:
                setid, caseid = f, 1
            
            setid = int(setid) if setid != 'sample' else 0
            caseid = int(caseid) if caseid != 'sample' else 1

            entry = _TestEntry(setid, caseid)
            if out:
                entry.fout = os.path.join(folder, name)
            else:
                entry.fin = os.path.join(folder, name)
            entry_dict[name[:name.rfind('.')]] = entry
    
    entries = sorted(list(entry_dict.values()))
    group, setid = [], ''
    for entry in entries:
        if entry.setid != setid:
            group.append({
                'setid': entry.setid,
                'cases': []
            })
            setid = entry.setid
        
        group[-1]['cases'].append(entry)
    
    return group


def compile(src):
    if src.endswith('.py'):
        return
    
    CPP_COMPILE_CMD[-1] = src
    proc = sp.Popen(CPP_COMPILE_CMD, stderr=sp.PIPE)
    err = [line.decode('utf-8').strip() for line in proc.stderr]

    success = os.path.isfile(COMPILE_OUT)
    return success, err


def run(case_group, lang, limit):
    total = passed = 0

    cmd = RUN_CMD[lang]
    for group in case_group:
        setid = 'sample' if group['setid'] == 0 else group['setid']
        print(f'Test Set {setid}')
        success = True

        for case in group['cases']:
            if args.early_stop and not success:
                print(f'Case #{case.caseid:02d}: -- | Runtime: --, Memory: --')
                continue

            stats = {}
            with open(case.fin, 'r') as fin, open(RUN_OUT, 'w') as fout, open(ERROR_OUT, 'w') as ferr:
                try:
                    proc = sp.run(cmd, stdin=fin, stdout=fout, stderr=ferr, timeout=limit+1)
                except sp.TimeoutExpired:
                    stats['time'] = limit+1
                    stats['memory'] = -1
            
            
            with open(ERROR_OUT, 'r') as f:
                for line in f:
                    line = line.strip()
                    if line.startswith('User time'):
                        stats['time'] = float(line[line.rfind(':')+1:])
                    elif line.startswith('Maximum resident set size'):
                        stats['memory'] = float(line[line.rfind(':')+1:]) / 1000
            
            case.time = stats['time']
            case.memory = stats['memory']

            if proc.returncode != 0:
                if proc.stderr:
                    print(proc.stderr.decode('utf-8'))
                case.rtype = TEST_RESULT_TYPE['runtime_error']
            elif stats['time'] > limit:
                case.rtype = TEST_RESULT_TYPE['time_limit_exceed']
            elif stats['memory'] > MEMORY_LIMIT:
                case.rtype = TEST_RESULT_TYPE['memory_limit_exceed']
            else:
                ok = test(case)
                case.rtype = TEST_RESULT_TYPE['pass'] if ok else TEST_RESULT_TYPE['wrong_answer']
            
            ok = case.rtype == TEST_RESULT_TYPE['pass']
            success &= ok
            
            if case.rtype == TEST_RESULT_TYPE['time_limit_exceed']:
                time = f'{limit:.2f}+'
                memory = ' -- '
            else:
                time = f'{case.time:.2f}s'
                memory = f'{case.memory:.3f}'
            print(f'Case #{case.caseid:02d}: {case.rtype} | Runtime: {time}, Memory: {memory}MB')
        print()
        
        group['status'] = 'Pass' if success else 'Fail'
        if setid != 'sample':
            total += 1
            if success:
                passed += 1
    print(f'Total {passed}/{total} test sets passed.')
            

def test(case):
    fout = case.fout

    if args.ans_threshold != -1:
        return _test_num_close(RUN_OUT, fout)
    elif args.test_file:
        return _script_test(args.test_file, case.fin, RUN_OUT, fout)
    else:
        return _test_diff(fout)


def _test_diff(sol):
    COMPARE_CMD[-1] = sol
    proc = sp.run(COMPARE_CMD, stdout=sp.PIPE, stderr=sp.PIPE)
    if proc.stdout:
        print(proc.stdout.decode('utf-8'))
    if proc.stderr:
        print(proc.stderr.decode('utf-8'))
    
    return not proc.stderr and not proc.stdout


def _test_num_close(ans, sol):
    with open(ans, 'r') as fans, open(sol, 'r') as fsol:
        for la, ls in itertools.zip_longest(iter(fans), iter(fsol), fillvalue=''):
            
            if not la or not ls:
                return False
            try:
                la, ls = float(la), float(ls)
                if abs(la - ls) > args.ans_threshold:
                    return False
            except Exception:
                return False
    return True


def _script_test(test_file, input_file, ans, sol):
    SCRIPT_TEST_CMD[1] = test_file
    SCRIPT_TEST_CMD[2] = input_file
    SCRIPT_TEST_CMD[-1] = sol
    proc = sp.run(SCRIPT_TEST_CMD, stdout=sp.PIPE, stderr=sp.PIPE)
    if proc.stdout:
        print(proc.stdout.decode('utf-8'))
    if proc.stderr:
        print(proc.stderr.decode('utf-8'))
    return not proc.stderr and not proc.stdout


def print_result(case_group):
    # not used
    total = ok = 0
    for group in case_group:
        setid = 'Sample' if group['setid'] == 0 else group['setid']
        print(f'Test Set {setid}: {group["status"]}')
        if setid != 'Sample':
            total += 1
            if (group['status'] == 'Pass'):
                ok += 1
        for case in group['cases']:
            print(f'Case #{case.caseid}: {case.rtype} | Runtime: {case.time:.2f}s, Memory: {case.memory:.3f}MB')
        print()
    
    print(f'Total {ok}/{total} test sets passed.')


def cleanup(compile_file=True):
    if compile_file and os.path.exists(COMPILE_OUT):
        os.remove(COMPILE_OUT)
    if os.path.exists(RUN_OUT):
        os.remove(RUN_OUT)
    if os.path.exists(ERROR_OUT):
        os.remove(ERROR_OUT)


def check(src, test_folder, lang, limit):
    # cleanup old files
    cleanup()

    # file src file
    if not os.path.isfile(src):
        print(f"File {os.path.abspath(src)} does not exist.")
    
    # list test cases
    if not os.path.isdir(test_folder):
        print(f"Path {os.path.abspath(test_folder)} does not exist or is not a folder.")
    case_group = find_test_cases(test_folder)

    # compile src if needed
    success, error = compile(src)
    if error:
        for line in error:
            print(line)
    if not success:
        print(FAIL_SCRIPT.format(TEST_RESULT_TYPE['compile_error']))
        sys.exit(1)

    # run src on test cases
    run(case_group, lang, limit)

    # cleanup, keep compile files in case manual debugging is needed
    cleanup(args.cleanup)


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--source-file', '-s', type=str, help='source program file', required=True)
    parser.add_argument('--test-case-folder', '-c', type=str, help='test folder', required=True)
    parser.add_argument('--language', '-l', type=str, help='language used. Now support cpp and py', required=True)
    parser.add_argument('--ans-threshold', '-a', type=float, help='Threshold to numeric answers.', required=False, default=-1)
    parser.add_argument('--test-file', '-t', type=str, help='program to test correctness', required=False)
    parser.add_argument('--timeout', '-e', type=float, help='timeout limit on each test case.', required=False, default=2)
    parser.add_argument('--cleanup', '-d', type=str, help='delete compiled file after finishing the testing', required=False, default='')
    parser.add_argument('--early-stop', '-f', type=str, help='stop current test set when one case if failed', default='')

    args = parser.parse_args()
    if args.language not in {'cpp', 'py'}:
        print('Language only support cpp or py now.')
        sys.exit(1)
    if args.ans_threshold != -1 and args.test_file:
        print('ans-threshold and test_file cannot be set together.')
        sys.exit(1)

    check(args.source_file, args.test_case_folder, args.language, args.timeout)
