class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        # Initialize variables
        max_sum = current_sum = nums[0]
        
        # Iterate through the array starting from the second element
        for num in nums[1:]:
            # Update current_sum to either the current number itself or current_sum + num
            current_sum = max(num, current_sum + num)
            
            # Update max_sum to the maximum of max_sum or current_sum
            max_sum = max(max_sum, current_sum)
        
        return max_sum
