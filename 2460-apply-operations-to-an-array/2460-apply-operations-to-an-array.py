
class Solution:
    def applyOperations(self, nums: List[int]) -> List[int]:
        n = len(nums)
        nz = 0  # Pointer for placing non-zero elements
        
        # First pass: Double adjacent equal elements and set the next one to zero
        for i in range(n - 1):
            if nums[i] != 0 and nums[i] == nums[i + 1]:
                nums[i] *= 2
                nums[i + 1] = 0
        
        # Second pass: Move non-zero elements forward
        for i in range(n):
            if nums[i] != 0:
                nums[i], nums[nz] = nums[nz], nums[i]
                nz += 1
        
        return nums
