class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        # Find unique characters
        unique_chars = set(s)
        n = len(s)
        count = 0

        for ch in unique_chars:
            first, last = -1, -1

            # Find first and last occurrence of character `ch`
            for i in range(n):
                if s[i] == ch:
                    if first == -1:
                        first = i
                    last = i
            
            if first == last:
                continue

            # Find unique characters between first and last occurrence
            unique_between = set(s[first + 1:last])
            count += len(unique_between)

        return count
