class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        """
        Calculate the maximum profit from one buy-sell transaction.
        """
        # Initialize variables
        min_price = float('inf')  # Keep track of the minimum price encountered
        max_profit = 0  # Keep track of the maximum profit
        
        # Traverse through the prices
        for price in prices:
            # Update the minimum price
            if price < min_price:
                min_price = price
            # Calculate profit and update max profit
            elif price - min_price > max_profit:
                max_profit = price - min_price
        
        return max_profit
    