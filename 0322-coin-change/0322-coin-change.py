
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        memo = {}

        def helper(remaining: int) -> int:
            if remaining == 0:
                return 0
            if remaining < 0:
                return float('inf')
            if remaining in memo:
                return memo[remaining]

            min_coins = float('inf')
            for coin in coins:
                res = helper(remaining - coin)
                if res != float('inf'):
                    min_coins = min(min_coins, res + 1)

            memo[remaining] = min_coins
            return min_coins

        result = helper(amount)
        return result if result != float('inf') else -1