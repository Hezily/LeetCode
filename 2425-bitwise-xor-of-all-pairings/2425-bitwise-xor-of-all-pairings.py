class Solution:
    def xorAllNums(self, nums1: list[int], nums2: list[int]) -> int:
        n = len(nums1)
        m = len(nums2)
        res = 0
        
        # If the length of nums1 is odd, XOR all elements in nums2
        if n % 2 != 0:
            for num in nums2:
                res ^= num
        
        # If the length of nums2 is odd, XOR all elements in nums1
        if m % 2 != 0:
            for num in nums1:
                res ^= num
        
        return res
   