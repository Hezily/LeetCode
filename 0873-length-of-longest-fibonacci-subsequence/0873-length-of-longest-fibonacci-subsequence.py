
class Solution:
    def lenLongestFibSubseq(self, arr: List[int]) -> int:
        n = len(arr)
        dp = [[0] * n for _ in range(n)]
        max_len = 0
        
        for cur in range(2, n):
            start, end = 0, cur - 1
            while start < end:
                sum_val = arr[start] + arr[end]
                if sum_val < arr[cur]:
                    start += 1
                elif sum_val > arr[cur]:
                    end -= 1
                else:
                    dp[end][cur] = dp[start][end] + 1
                    max_len = max(max_len, dp[end][cur])
                    start += 1
                    end -= 1
        
        return 0 if max_len == 0 else max_len + 2
        