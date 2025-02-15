class Solution:
    def isPartition(self, j: int, i2: str, i: int, curSum: int) -> bool:
        n = len(i2)
        # Base case
        if j == n:
            return curSum == i
        
        for index in range(j, n):
            val = int(i2[j:index+1])
            if self.isPartition(index + 1, i2, i, curSum + val):
                return True
        
        return False
    
    def punishmentNumber(self, n: int) -> int:
        res = 0
        for i in range(1, n + 1):
            i2 = str(i * i)
            if self.isPartition(0, i2, i, 0):
                res += (i * i)
        return res