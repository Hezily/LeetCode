class Solution:
    def maximumCount(self, nums: List[int]) -> int:
        a, b = 0, 0
        for num in nums:
            if num < 0:
                a += 1
            elif num > 0:
                b += 1
        return max(a, b)

