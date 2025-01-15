class Solution:
    def findMissingAndRepeatedValues(self, grid: List[List[int]]) -> List[int]:
        # Flatten the grid into a 1D array
        nums = [num for row in grid for num in row]
        
        # Get the size of the grid (n x n)
        n = len(grid)
        total_elements = n * n  # Total numbers from 1 to n^2
        
        # Calculate expected sum and sum of squares
        expected_sum = total_elements * (total_elements + 1) // 2
        expected_sum_sq = total_elements * (total_elements + 1) * (2 * total_elements + 1) // 6

        # Calculate actual sum and sum of squares from the grid
        actual_sum = sum(nums)
        actual_sum_sq = sum(x * x for x in nums)

        # Calculate differences
        diff = expected_sum - actual_sum  # b - a (missing - repeated)
        diff_sq = expected_sum_sq - actual_sum_sq  # b^2 - a^2

        # Solve for missing (b) and repeated (a)
        sum_mr = diff_sq // diff  # b + a
        missing = (diff + sum_mr) // 2
        repeated = sum_mr - missing

        return [repeated, missing]