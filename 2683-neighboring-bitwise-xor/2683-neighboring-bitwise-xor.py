class Solution:
    def doesValidArrayExist(self, derived: list[int]) -> bool:
        res = 0
        for val in derived:
            res ^= val
        return res == 0
