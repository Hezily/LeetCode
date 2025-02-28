class Solution:
    def shortestCommonSupersequence(self, str1: str, str2: str) -> str:
        dp = self.longestCommonSubsequence(str1, str2)
        n, m = len(dp), len(dp[0])
        i, j = n - 1, m - 1
        sb = []
        
        while i > 0 and j > 0:
            if str1[i - 1] == str2[j - 1]:  # lcs
                sb.append(str1[i - 1])
                i -= 1
                j -= 1
            elif dp[i - 1][j] > dp[i][j - 1]:
                sb.append(str1[i - 1])
                i -= 1
            else:
                sb.append(str2[j - 1])
                j -= 1
        
        while i > 0:
            sb.append(str1[i - 1])
            i -= 1
        
        while j > 0:
            sb.append(str2[j - 1])
            j -= 1
        
        return "".join(reversed(sb))
    
    def longestCommonSubsequence(self, text1: str, text2: str):
        n, m = len(text1), len(text2)
        dp = [[0] * (m + 1) for _ in range(n + 1)]
        
        for i in range(1, n + 1):
            for j in range(1, m + 1):
                if text1[i - 1] == text2[j - 1]:
                    dp[i][j] = 1 + dp[i - 1][j - 1]
                else:
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
        
        return dp
