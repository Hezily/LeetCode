class Solution:
    def hammingWeight(self, n: int) -> int:
        count = 0
        while n:
            n = n & (n - 1)  # Remove the rightmost set bit
            count += 1
        return count    