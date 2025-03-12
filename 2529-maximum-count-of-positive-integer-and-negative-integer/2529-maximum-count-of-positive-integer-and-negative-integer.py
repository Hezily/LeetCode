
class Solution:
    def maximumCount(self, nums: List[int]) -> int:
        neg_count = sum(1 for num in nums if num < 0)
        pos_count = sum(1 for num in nums if num > 0)
        return max(neg_count, pos_count)
