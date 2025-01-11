class Solution:
    def canConstruct(self, s: str, k: int) -> bool:
        n = len(s)
        if n < k:
            return False
        if n == k:
            return True
        
        # Count the frequency of each character
        count = [0] * 26
        for char in s:
            count[ord(char) - ord('a')] += 1
        
        # Count characters with odd frequency
        odd_count = sum(1 for freq in count if freq % 2 == 1)
        
        # Check if the odd counts can fit within k
        return odd_count <= k
