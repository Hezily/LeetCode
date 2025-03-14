class Solution:
    def maximumCandies(self, candies: List[int], k: int) -> int:
        if sum(candies) < k:  # If total candies are less than children, return 0
            return 0
        
        left, right = 1, max(candies)
        result = 0
        
        while left <= right:
            mid = (left + right) // 2  # Mid represents the potential maximum candies per child
            count = sum(c // mid for c in candies)  # Count children who can get at least 'mid' candies
            
            if count >= k:  # If we can serve at least k children
                result = mid  # Store the valid result
                left = mid + 1  # Try for a higher value
            else:
                right = mid - 1  # Reduce the max possible candies per child
        
        return result
