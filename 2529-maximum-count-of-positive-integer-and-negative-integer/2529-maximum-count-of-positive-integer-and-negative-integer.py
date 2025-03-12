
class Solution:
    def maximumCount(self, nums: List[int]) -> int:
        a = sum(1 for num in nums if num < 0)
        b = sum(1 for num in nums if num > 0)
        return max(a,b)
