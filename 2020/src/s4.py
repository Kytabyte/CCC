import collections
import itertools
import functools
import math
import re
import bisect
import random

rint = lambda: int(input())
rstr = lambda: input()
rints = lambda: list(map(int, input().split()))
rstrs = lambda: input().split()
wmat = lambda n, mat, sep: '{}\n{}'.format(n, '\n'.join(sep.join(map(str, row)) for row in mat))
warr = lambda n, arr, sep: '{}\n{}'.format(n, sep.join(map(str, arr)))
wl = lambda sep, *arr: sep.join(map(str, arr))

ctoi = lambda x : ord(x) - ord('A')
itoc = lambda x : chr(x + ord('A'))

def main():
    s = rstr()
    N = len(s)

    ps = [[0] * (N+1) for _ in range(3)]
    for i in range(3):
        for j, ch in enumerate(s, 1):
            ps[i][j] = ps[i][j-1] + (ctoi(ch) == i)
    
    def query(i, s, l):
        return ps[i][s+l] - ps[i][s]

    def solve(a, b, c):
        Na, Nb = ps[a][-1], ps[b][-1]
        Nab = Na + Nb

        ans = math.inf
        for i in range(N - Nab + 1):
            na, nb, nc = query(a, i, Nab), query(b, i, Nab), query(c, i, Nab)
            da, db = Na - na, Nb - nb

            fa, fb = query(a, i, Na), query(b, i, Nb)
            fca, fcb = query(c, i, Na), query(c, i, Nb)

            cur = nc + min(Na - (fa + min(da, fca)), Nb - (fb + min(db, fcb)))
            ans = min(cur, ans)
        return ans
    
    ans = math.inf
    for a, b, c in itertools.permutations(range(3)):
        ans = min(ans, solve(a, b, c))
    print(ans)


if __name__ == '__main__':
    main()
