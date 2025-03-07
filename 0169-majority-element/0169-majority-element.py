class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        sorted_arr = sorted(nums)
        n = len(nums)
        return sorted_arr[n//2]
