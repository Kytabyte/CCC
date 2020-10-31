import itertools
import collections

def transform(nums):
    N = len(nums)
    new = [0] * N
    for i in range(N):
        new[i] = nums[i-1] ^ nums[(i+1) % N]
    return tuple(new)

def run(nums):
    memo = collections.OrderedDict()

    i = 0
    while (nums not in memo):
        memo[nums] = i
        i += 1
        nums = transform(nums)
    
    return (len(memo) - memo[nums])

for i in range(3, 100):
    nums = tuple([0] * (i-1) + [1])
    print(i, run(nums))
# n = int(input())
# for nums in itertools.product(range(2), repeat=n):
#     run(nums)

