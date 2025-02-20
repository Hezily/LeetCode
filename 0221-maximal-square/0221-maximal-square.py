class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        if not matrix:
            return 0
        
        m, n = len(matrix), len(matrix[0])
        dp = [0] * (n + 1)
        max_side, prev = 0, 0

        for i in range(m):
            for j in range(1, n + 1):
                temp = dp[j]
                if matrix[i][j - 1] == '1':
                    dp[j] = min(dp[j], dp[j - 1], prev) + 1
                    max_side = max(max_side, dp[j])
                else:
                    dp[j] = 0
                prev = temp  # Store previous row's value

        return max_side * max_side
