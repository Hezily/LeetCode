from typing import List

class Solution:
    def minZeroArray(self, nums: List[int], queries: List[List[int]]) -> int:
        n = len(nums)
        diff = [0] * (n + 1)

        for k, (l, r, val) in enumerate(queries):
            diff[l] -= val
            diff[r + 1] += val

            curr = 0
            all_zero = True
            for i in range(n):
                curr += diff[i]
                if nums[i] + curr > 0:
                    all_zero = False

            if all_zero:
                return k + 1

        return -1
