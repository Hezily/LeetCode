class Solution:
    def minCost(self, grid, use_dijkstra=True):
        rows, cols = len(grid), len(grid[0])
        dirs = [(0, 1), (0, -1), (1, 0), (-1, 0)]  # Directions: right, left, down, up
        minCost = [[float('inf')] * cols for _ in range(rows)]
        minCost[0][0] = 0

        if use_dijkstra:
            # Dijkstra's algorithm
            pq = [(0, 0, 0)]  # (cost, row, col)

            while pq:
                cost, row, col = heapq.heappop(pq)

                if cost > minCost[row][col]:
                    continue

                for dir_idx, (dx, dy) in enumerate(dirs):
                    nextRow, nextCol = row + dx, col + dy

                    if 0 <= nextRow < rows and 0 <= nextCol < cols:
                        nextCellCost = 0 if dir_idx + 1 == grid[row][col] else 1
                        newCost = cost + nextCellCost

                        if newCost < minCost[nextRow][nextCol]:
                            minCost[nextRow][nextCol] = newCost
                            heapq.heappush(pq, (newCost, nextRow, nextCol))
        else:
            # 0-1 BFS
            deque_ = deque([(0, 0)])  # (row, col)

            while deque_:
                row, col = deque_.popleft()
                cost = minCost[row][col]

                for dir_idx, (dx, dy) in enumerate(dirs):
                    nextRow, nextCol = row + dx, col + dy

                    if 0 <= nextRow < rows and 0 <= nextCol < cols:
                        nextCellCost = 0 if dir_idx + 1 == grid[row][col] else 1
                        newCost = cost + nextCellCost

                        if newCost < minCost[nextRow][nextCol]:
                            minCost[nextRow][nextCol] = newCost
                            if nextCellCost == 0:
                                deque_.appendleft((nextRow, nextCol))
                            else:
                                deque_.append((nextRow, nextCol))

        return minCost[rows - 1][cols - 1]
