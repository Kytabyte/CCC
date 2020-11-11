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
wmat = lambda mat, sep: '\n'.join(sep.join(map(str, row)) for row in mat)
warr = lambda arr, sep: sep.join(map(str, arr))
wl = lambda sep, *arr: sep.join(map(str, arr))

ctoi = lambda x : ord(x) - ord('a')
itoc = lambda x : chr(x + ord('a'))


grid = [
    [[[1,2],[3,4]], [[2,1],[4,3]]],
    [[[3,4],[1,2]], [[4,3],[2,1]]]
]

def main():
    s = rstr()
    h = v = 0
    for ch in s:
        if ch == 'H':
            h = 1 - h
        else:
            v = 1 - v
    print(wmat(grid[h][v], ' '))

if __name__ == '__main__':
    main()
