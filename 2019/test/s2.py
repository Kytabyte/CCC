import itertools
import sys
import os


def isprime(n):
    i = 2
    while i * i <= n:
        if n % i == 0:
            return False
        i += 1
    return True


def test(fin, sol, ans):
    with open(ans, 'r') as fa, open(sol, 'r') as fs:
        for la, ls in itertools.zip_longest(iter(fa), iter(fs), fillvalue=''):
            assert la
            assert ls
            a, b = list(map(int, la.split()))
            c, d = list(map(int, ls.split()))
            assert isprime(a)
            assert isprime(b)
            assert a + b == c + d


if __name__ == "__main__":
    if len(sys.argv) != 4:
        print('Usage: python3 s2.py input_file sol_file ans_file')
    else:
        fin, sol, ans = sys.argv[1:]
        test(fin, sol, ans)
