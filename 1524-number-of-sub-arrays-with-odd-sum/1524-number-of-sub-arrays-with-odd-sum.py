class Solution:
    def numOfSubarrays(self, arr):
        Mod = 1000000007
        evenC = 1
        oddC = 0
        prefix = 0
        res = 0
        
        for num in arr:
            prefix += num
            if prefix % 2 == 0:
                res += oddC
                evenC += 1
            else:
                res += evenC
                oddC += 1
            res %= Mod
        
        return res
