class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        left, right = 0, len(nums) - 1

        while left < right:
            mid = (left + right) // 2
            if nums[mid] > nums[mid + 1]:  
                right = mid  # Peak is in the left half
            else:
                left = mid + 1  # Peak is in the right half

        return left  # 'left' will point to a peak element index
