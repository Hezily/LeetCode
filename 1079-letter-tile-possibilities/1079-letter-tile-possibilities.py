class Solution:
    def numTilePossibilities(self, tiles: str) -> int:
        def backtrack(freq):
            count = 0
            for i in range(26):
                if freq[i] == 0:
                    continue
                count += 1
                freq[i] -= 1
                count += backtrack(freq)
                freq[i] += 1
            return count
        
        freq = [0] * 26
        for char in tiles:
            freq[ord(char) - ord('A')] += 1
        
        return backtrack(freq)

    