class Solution:
    def maxScore(self, s: str) -> int:
        n = len(s)

        # Precompute the count of ones in the entire string
        total_ones = s.count('1')

        max_score = 0
        left_zeros = 0
        right_ones = total_ones

        # Iterate through possible split points
        for i in range(n - 1):  # We stop at n-1 to ensure both substrings are non-empty
            if s[i] == '0':
                left_zeros += 1
            else:
                right_ones -= 1

            # Calculate and update the maximum score
            max_score = max(max_score, left_zeros + right_ones)

        return max_score
