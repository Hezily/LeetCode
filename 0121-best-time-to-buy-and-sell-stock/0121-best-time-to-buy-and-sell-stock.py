class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        """
        Calculate the maximum profit from one buy-sell transaction.
        """
        min_price = float('inf')
        max_profit = 0
        
        for price in prices:
            if price < min_price:
                min_price = price
            elif price - min_price > max_profit:
                max_profit = price - min_price
        
        return max_profit
   