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
wl = lambda *arr: ' '.join(map(str, arr))

