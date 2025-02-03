from typing import List

class Solution:
    def longestMonotonicSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1:
            return 1

        inc_len = 1  # Length of the current strictly increasing subarray
        dec_len = 1  # Length of the current strictly decreasing subarray
        max_len = 1  # Maximum length of the monotonic subarray

        for i in range(1, n):
            if nums[i] > nums[i - 1]:  # Strictly increasing
                inc_len += 1
                dec_len = 1  # Reset decreasing length
            elif nums[i] < nums[i - 1]:  # Strictly decreasing
                dec_len += 1
                inc_len = 1  # Reset increasing length
            else:  # Equal elements, reset both
                inc_len = 1
                dec_len = 1
            
            max_len = max(max_len, inc_len, dec_len)

        return max_len