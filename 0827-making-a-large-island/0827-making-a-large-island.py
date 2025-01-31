class Solution:
    def largestIsland(self, grid: List[List[int]]) -> int:
        n = len(grid)
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        island_id = 2  # Start island IDs from 2
        island_sizes = {0: 0}  # Map island ID to its size
        
        def dfs(r, c, id):
            stack = [(r, c)]
            size = 0
            while stack:
                x, y = stack.pop()
                if grid[x][y] == 1:
                    grid[x][y] = id
                    size += 1
                    for dx, dy in directions:
                        nx, ny = x + dx, y + dy
                        if 0 <= nx < n and 0 <= ny < n and grid[nx][ny] == 1:
                            stack.append((nx, ny))
            return size
        
        # Step 1: Find all islands and mark them with a unique ID
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1:
                    island_sizes[island_id] = dfs(i, j, island_id)
                    island_id += 1
        
        max_island = max(island_sizes.values(), default=0)
        
        # Step 2: Try changing each 0 to 1 and calculate possible max size
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 0:
                    seen = set()
                    new_size = 1  # Include the converted 1 itself
                    for dx, dy in directions:
                        ni, nj = i + dx, j + dy
                        if 0 <= ni < n and 0 <= nj < n and grid[ni][nj] > 1:
                            island_id = grid[ni][nj]
                            if island_id not in seen:
                                seen.add(island_id)
                                new_size += island_sizes[island_id]
                    max_island = max(max_island, new_size)
        
        return max_island