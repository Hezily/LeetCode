class Solution:
    def finalPrices(self, prices):
        stack = []
        
        for i in range(len(prices)):  # O(N)
            while stack and prices[stack[-1]] >= prices[i]:  # Check if there's a price smaller than the current one
                idx = stack.pop()
                prices[idx] -= prices[i]  # Reduce the price at the popped index by current price
            stack.append(i)  # Add the current index to the stack
        
        return prices
