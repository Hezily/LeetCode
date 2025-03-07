class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        left, right = 1, max(piles)
        
        while left < right:
            mid = (left + right) // 2
            total_hours = sum(ceil(pile / mid) for pile in piles)
            
            if total_hours > h:
                left = mid + 1
            else:
                right = mid 
        
        return left 
