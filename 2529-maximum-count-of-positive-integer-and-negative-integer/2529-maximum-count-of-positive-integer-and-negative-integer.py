# class Solution:
#     def maximumCount(self, nums: List[int]) -> int:
        # a, b = 0, 0
        # for num in nums:
        #     if num < 0:
        #         a += 1
        #     elif num > 0:
        #         b += 1
        # return max(a, b)

from typing import List

class Solution:
    def maximumCount(self, nums: List[int]) -> int:
        def binarySearchFirstNonNegative(nums):
            left, right = 0, len(nums) - 1
            while left <= right:
                mid = left + (right - left) // 2
                if nums[mid] < 0:
                    left = mid + 1  # Move right to find first non-negative
                else:
                    right = mid - 1  # Keep moving left
            return left  # First non-negative index

        def binarySearchFirstPositive(nums):
            left, right = 0, len(nums) - 1
            while left <= right:
                mid = left + (right - left) // 2
                if nums[mid] <= 0:
                    left = mid + 1  # Move right to find first positive
                else:
                    right = mid - 1  # Keep moving left
            return left  # First positive index

        neg_count = binarySearchFirstNonNegative(nums)  # Count of negative numbers
        pos_count = len(nums) - binarySearchFirstPositive(nums)  # Count of positive numbers
        return max(neg_count, pos_count)
