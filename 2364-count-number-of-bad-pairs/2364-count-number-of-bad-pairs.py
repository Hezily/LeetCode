class Solution:
    def countBadPairs(self, nums: List[int]) -> int:
        n = len(nums)
        good_pairs = 0
        total_pairs = n * (n - 1) // 2
        count_map = defaultdict(int)
        
        for i, num in enumerate(nums):
            val = i - num
            good_pairs += count_map[val]
            count_map[val] += 1
        
        return total_pairs - good_pairs