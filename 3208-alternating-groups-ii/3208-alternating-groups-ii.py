class Solution:
    def numberOfAlternatingGroups(self, colors: list[int], k: int) -> int:
        res, left, n = 0, 0, len(colors)

        for right in range(1, n + k - 1):
            if colors[right % n] == colors[(right - 1) % n]:
                left = right
            
            if right - left + 1 >= k:
                res += 1
                left += 1 
        
        return res
