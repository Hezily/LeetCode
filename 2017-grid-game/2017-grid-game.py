class Solution:
    def gridGame(self, grid: list[list[int]]) -> int:
        # Calculate the initial top sum
        top_sum = sum(grid[0])
        bottom_sum = 0
        ans = float('inf')
        n = len(grid[0])

        for p in range(n):
            # Subtract the current value from the top sum
            top_sum -= grid[0][p]
            # Find the minimum of the maximum sums
            ans = min(ans, max(top_sum, bottom_sum))
            # Add the current value to the bottom sum
            bottom_sum += grid[1][p]

        return ans
