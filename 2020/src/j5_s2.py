import collections
import itertools
import functools
import math
import re
import bisect
import random
import sys

rint = lambda: int(input())
rstr = lambda: input()
rints = lambda: list(map(int, input().split()))
rstrs = lambda: input().split()
wmat = lambda n, mat, sep: '{}\n{}'.format(n, '\n'.join(sep.join(map(str, row)) for row in mat))
warr = lambda n, arr, sep: '{}\n{}'.format(n, sep.join(map(str, arr)))
wl = lambda sep, *arr: sep.join(map(str, arr))

def main():
    m, n = rint(), rint()

    grid = []
    for _ in range(m):
        grid.append(rints())
    
    factors = collections.defaultdict(list)

    def calc(num):
        i = 1
        f = factors[num]
        while i * i <= num:
            if num % i == 0 and i <= max(n, m) and num // i <= max(n, m):
                f.append(i)
            i += 1
        return num

    def dfs(i, j):
        if i == m - 1 and j == n - 1:
            return True

        if i >= m or j >= n or grid[i][j] in factors:
            return False
        
        num = calc(grid[i][j])
        for ni in factors[num]:
            nj = num // ni

            if dfs(ni-1, nj-1) or dfs(nj-1, ni-1):
                return True
        return False
    
    print('yes' if dfs(0, 0) else 'no')
        

if __name__ == '__main__':
    sys.setrecursionlimit(int(1e6 + 5))
    main()
