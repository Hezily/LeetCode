class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        # Create a DP table initialized to 1 for the first row and column
        dp = [[1] * n for _ in range(m)]
        
        # Fill the DP table using the recurrence relation
        for i in range(1, m):
            for j in range(1, n):
                dp[i][j] = dp[i-1][j] + dp[i][j-1]
        
        # The result is stored in the bottom-right corner of the table
        return dp[m-1][n-1]
   