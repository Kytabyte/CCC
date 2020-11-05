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
    T, S = rstr(), rstr()
    l = len(S)
    S *= 2

    yes = any(T[i:i+l] in S for i in range(len(T) - l + 1))
    print('yes' if yes else 'no')

if __name__ == '__main__':
    main()
