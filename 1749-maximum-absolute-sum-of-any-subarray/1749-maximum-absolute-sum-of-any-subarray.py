class Solution:
    def maxAbsoluteSum(self, nums: list[int]) -> int:
        max_sum = float('-inf')
        min_sum = float('inf')
        cur_p_sum = 0
        cur_n_sum = 0
        
        for num in nums:
            # Positive subarray sum
            cur_p_sum += num
            max_sum = max(max_sum, cur_p_sum)
            if cur_p_sum < 0:
                cur_p_sum = 0
            
            # Negative subarray sum
            cur_n_sum += num
            min_sum = min(min_sum, cur_n_sum)
            if cur_n_sum > 0:
                cur_n_sum = 0
        
        return max(max_sum, abs(min_sum))
