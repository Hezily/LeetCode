class Solution:
    def countServers(self, grid):
        n = len(grid)
        m = len(grid[0])
        row_count = [0] * n
        col_count = [0] * m
        count = 0
        
        # Count servers in each row and column
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1:
                    row_count[i] += 1
                    col_count[j] += 1
                    count += 1
        
        # Remove isolated servers
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1:
                    if row_count[i] == 1 and col_count[j] == 1:
                        count -= 1
        
        return count
