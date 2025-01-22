from collections import deque

class Solution:
    def highestPeak(self, isWater: list[list[int]]) -> list[list[int]]:
        # Directions for up, right, down, left
        directions = [(-1, 0), (0, 1), (1, 0), (0, -1)]
        
        n = len(isWater)
        m = len(isWater[0])
        res = [[-1] * m for _ in range(n)]
        queue = deque()

        # Fill the queue with water cells and initialize result grid
        for i in range(n):
            for j in range(m):
                if isWater[i][j] == 1:
                    res[i][j] = 0
                    queue.append((i, j))
        
        # BFS to assign heights
        while queue:
            r, c = queue.popleft()
            height = res[r][c]
            
            for dr, dc in directions:
                nr, nc = r + dr, c + dc
                if 0 <= nr < n and 0 <= nc < m and res[nr][nc] == -1:
                    res[nr][nc] = height + 1
                    queue.append((nr, nc))
        
        return res
 