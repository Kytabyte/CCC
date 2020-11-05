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
    n = rint()
    xmin = ymin = math.inf
    xmax = ymax = -math.inf

    for _ in range(n):
        x, y = map(int, input().split(','))
        xmin = min(xmin, x)
        ymin = min(ymin, y)
        xmax = max(xmax, x)
        ymax = max(ymax, y)
    
    print(wl(',', xmin-1, ymin-1))
    print(wl(',', xmax+1, ymax+1))

if __name__ == '__main__':
    main()
