class Solution:
    def __init__(self):
        self.rows = 0
        self.cols = 0

    def findMaxFish(self, grid):
        self.rows = len(grid)
        self.cols = len(grid[0])
        max_fishes = 0

        # Iterate through all cells in the grid
        for i in range(self.rows):
            for j in range(self.cols):
                if grid[i][j] != 0:  # If it's a water cell with fishes
                    max_fishes = max(max_fishes, self.dfs(i, j, grid))

        return max_fishes

    def dfs(self, r, c, grid):
        # Base cases: out of bounds or on a cell that has no fish or already visited
        if r < 0 or r >= self.rows or c < 0 or c >= self.cols or grid[r][c] == 0:
            return 0
        
        # Collect fish in the current cell
        ans = grid[r][c]
        grid[r][c] = 0  # Mark the cell as visited

        # Explore in all four directions
        ans += (self.dfs(r - 1, c, grid) + 
                self.dfs(r, c + 1, grid) + 
                self.dfs(r + 1, c, grid) + 
                self.dfs(r, c - 1, grid))
        return ans
