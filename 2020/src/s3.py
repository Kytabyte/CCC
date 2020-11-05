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

MOD1, MOD2 = int(1e9)+7, int(1e9)+31
MUL = 26

ctoi = lambda x : ord(x) - ord('a')

def main():
    N, H = rstr(), rstr()
    cnt_n = [0] * 26
    cnt_h = [0] * 26
    for ch in N:
        cnt_n[ctoi(ch)] += 1

    n, h = len(N), len(H)

    seen = set()
    hash1 = hash2 = 0
    pow1, pow2 = pow(26, n-1, MOD1), pow(26, n-1, MOD2)
    ans = 0
    for i in range(h):
        cnt_h[ctoi(H[i])] += 1
        hash1 = (hash1 * MUL + ctoi(H[i])) % MOD1
        hash2 = (hash2 * MUL + ctoi(H[i])) % MOD2

        if i >= n - 1:
            if cnt_h == cnt_n and (hash1, hash2) not in seen:
                ans += 1
                seen.add((hash1, hash2))
            
            cnt_h[ctoi(H[i-n+1])] -= 1
            hash1 = (hash1 - ctoi(H[i-n+1]) * pow1) % MOD1
            hash2 = (hash2 - ctoi(H[i-n+1]) * pow2) % MOD2
    
    print(ans)

if __name__ == '__main__':
    main()
