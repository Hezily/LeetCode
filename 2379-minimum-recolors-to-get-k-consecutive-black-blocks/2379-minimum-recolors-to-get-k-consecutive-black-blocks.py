class Solution:
    def minimumRecolors(self, blocks: str, k: int) -> int:
        # First window
        w = sum(1 for i in range(k) if blocks[i] == 'W')
        res = w
        n = len(blocks)
        
        # Next windows
        for i in range(1, n - k + 1):
            if blocks[i - 1] == 'W':
                w -= 1
            if blocks[i + k - 1] == 'W':
                w += 1
            res = min(res, w)
        
        return res
    