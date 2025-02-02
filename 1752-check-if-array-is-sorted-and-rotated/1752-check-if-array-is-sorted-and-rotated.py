class Solution:
    def check(self, nums: List[int]) -> bool:
        count = 0
        n = len(nums)
        
        for i in range(n):
            if nums[i] > nums[(i + 1) % n]:  # Check if the current element is greater than the next one
                count += 1
        
        return count <= 1  # If there's at most one descent, the array can be rotated and sorted
