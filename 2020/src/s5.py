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

def main():
    N = rint()
    burger = rints()

    c, j = burger[0], burger[-1]

    if c == j:
        print(1.0)
    else:
        seen = {c, j}
        pr = {c: 1.0}
        total = 1.0
        for i in reversed(range(1, N)):
            b = burger[i]
            if b not in seen:
                seen.add(b)
                pr[b] = total / (N - i)
            pr.setdefault(b, 0.0)
            total += pr[b]

        print(total / N)


if __name__ == '__main__':
    main()
