import sys
import os

def test(fin, sol, ans):
    rules = []
    with open(fin, 'r') as f:
        for line in f:
            if len(rules) < 3:
                rules.append(line.strip().split())
            else:
                step, src, dst = line.strip().split()
                step = int(step)
    
    with open(ans, 'r') as f:
        for line in f:
            rule, idx, trans = line.strip().split()
            rule, idx = int(rule)-1, int(idx)-1
            
            before, after = rules[rule]
            l = len(before)
            src = src[:idx] + after + src[idx+l:]
            assert src == trans
    
    assert src == dst
            

if __name__ == "__main__":
    if len(sys.argv) != 4:
        print('Usage: python3 j5.py input_file sol_file ans_file')
    else:
        fin, sol, ans = sys.argv[1:]
        test(fin, sol, ans)
