class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        # Initialize an empty list to hold the rows of Pascal's Triangle
        triangle = []

        for i in range(numRows):
            # Create a new row with 1's at both ends
            row = [1] * (i + 1)

            # Calculate the values for the middle elements
            for j in range(1, i):
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j]

            # Append the row to the triangle
            triangle.append(row)

        return triangle

