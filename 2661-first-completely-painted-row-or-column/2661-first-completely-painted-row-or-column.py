class Solution:
    def firstCompleteIndex(self, arr, mat):
        from collections import defaultdict

        n, m = len(mat), len(mat[0])  # Rows and columns
        row_count = [0] * n
        col_count = [0] * m
        value_to_index = {}

        # Map values in mat to their (row, column) positions
        for i in range(n):
            for j in range(m):
                value_to_index[mat[i][j]] = (i, j)

        # Traverse the order in arr
        for i, value in enumerate(arr):
            r, c = value_to_index[value]
            row_count[r] += 1
            col_count[c] += 1
            if row_count[r] == m or col_count[c] == n:
                return i

        return -1
