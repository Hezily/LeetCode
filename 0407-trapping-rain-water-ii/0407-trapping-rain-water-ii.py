import heapq

class Solution:
    def trapRainWater(self, heightMap):
        # Directions: left, right, down, up
        directions = [(0, -1), (0, 1), (-1, 0), (1, 0)]
        rows = len(heightMap)
        cols = len(heightMap[0])
        
        if rows < 3 or cols < 3:
            return 0
        
        total_unvisited_cells = rows * cols
        visited = [[False] * cols for _ in range(rows)]
        # Priority queue to store cells in increasing order of height
        pq = []
        
        # Add boundary cells to the priority queue and mark them as visited
        for i in range(rows):
            heapq.heappush(pq, (heightMap[i][0], i, 0))
            heapq.heappush(pq, (heightMap[i][cols - 1], i, cols - 1))
            visited[i][0] = True
            visited[i][cols - 1] = True
            total_unvisited_cells -= 2

        for j in range(1, cols - 1):
            heapq.heappush(pq, (heightMap[0][j], 0, j))
            heapq.heappush(pq, (heightMap[rows - 1][j], rows - 1, j))
            visited[0][j] = True
            visited[rows - 1][j] = True
            total_unvisited_cells -= 2

        trapped_water = 0
        water_level = 0
        
        # While there are cells to process and there are unvisited cells
        while pq and total_unvisited_cells > 0:
            current_height, current_row, current_col = heapq.heappop(pq)
            water_level = max(water_level, current_height)
            
            # Explore all 4 neighboring cells
            for dr, dc in directions:
                neighbor_row = current_row + dr
                neighbor_col = current_col + dc
                
                # Check if the neighbor is within bounds and not yet visited
                if self.is_valid_cell(neighbor_row, neighbor_col, rows, cols) and not visited[neighbor_row][neighbor_col]:
                    neighbor_height = heightMap[neighbor_row][neighbor_col]
                    if neighbor_height < water_level:
                        trapped_water += water_level - neighbor_height
                    heapq.heappush(pq, (neighbor_height, neighbor_row, neighbor_col))
                    visited[neighbor_row][neighbor_col] = True
                    total_unvisited_cells -= 1

        return trapped_water

    def is_valid_cell(self, row, col, rows, cols):
        return 0 <= row < rows and 0 <= col < cols
      