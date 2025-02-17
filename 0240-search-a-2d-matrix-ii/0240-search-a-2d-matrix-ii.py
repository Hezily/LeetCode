class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix:
            return False

        m, n = len(matrix), len(matrix[0])
        row, col = 0, n - 1  # Start from top-right corner

        while row < m and col >= 0:
            if matrix[row][col] == target:
                return True
            elif matrix[row][col] > target:
                col -= 1  # Move left
            else:
                row += 1  # Move down

        return False  # Target not found
