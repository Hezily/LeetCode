class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        freq = [0] * 3
        count = 0
        left = 0
        n = len(s)

        for right in range(n):
            freq[ord(s[right]) - ord('a')] += 1

            while all(f > 0 for f in freq):
                count += (n - right)
                freq[ord(s[left]) - ord('a')] -= 1
                left += 1

        return count
