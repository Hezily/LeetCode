class Solution:
    def tupleSameProduct(self, nums):
        product_map = defaultdict(int)
        n = len(nums)
        
        for i in range(n):
            for j in range(i + 1, n):
                res = nums[i] * nums[j]
                product_map[res] += 1
        
        ans = 0
        for count in product_map.values():
            if count >= 2:
                comb = (count * (count - 1)) // 2
                ans += comb * 8
        
        return ans
