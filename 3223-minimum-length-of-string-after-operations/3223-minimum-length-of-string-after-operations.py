class Solution:
    def minimumLength(self, s: str) -> int:
        freq = [0] * 26
        n = len(s)
        
        # Count the frequency of each character
        for char in s:
            freq[ord(char) - ord('a')] += 1
        
        # Calculate the minimum length
        count = 0
        for f in freq:
            if f > 0:
                count += 2 if f % 2 == 0 else 1
        
        return count
