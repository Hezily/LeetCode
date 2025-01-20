from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # Create a dictionary to store the value and its index
        num_to_index = {}

        # Iterate through the list
        for i, num in enumerate(nums):
            # Calculate the complement
            complement = target - num

            # Check if the complement exists in the dictionary
            if complement in num_to_index:
                # Return the indices of the current number and its complement
                return [num_to_index[complement], i]
            
            # Store the current number with its index
            num_to_index[num] = i
