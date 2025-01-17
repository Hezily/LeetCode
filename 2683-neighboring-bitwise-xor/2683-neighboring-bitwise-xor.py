class Solution:
    def doesValidArrayExist(self, derived: list[int]) -> bool:
        res = 0
        for val in derived:
            res ^= val
        
        if res!=0:
            return False
        else:
            return True
