class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # Initialize pointers
        low, mid, high = 0, 0, len(nums) - 1
        
        # Iterate through the array
        while mid <= high:
            if nums[mid] == 0:  # Red color
                nums[low], nums[mid] = nums[mid], nums[low]
                low += 1
                mid += 1
            elif nums[mid] == 1:  # White color
                mid += 1
            else:  # Blue color
                nums[mid], nums[high] = nums[high], nums[mid]
                high -= 1
