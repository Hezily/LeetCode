class Solution:
    def closestPrimes(self, left: int, right: int) -> List[int]:
        limit = right + 1
        is_prime = [True] * limit
        is_prime[0] = is_prime[1] = False

        for i in range(2, int(limit ** 0.5) + 1):
            if is_prime[i]:
                for j in range(i * i, limit, i):
                    is_prime[j] = False

        primes = [i for i in range(left, right + 1) if is_prime[i]]

        if len(primes) < 2:
            return [-1, -1]

        min_gap = float('inf')
        result = [-1, -1]

        for i in range(len(primes) - 1):
            if primes[i + 1] - primes[i] < min_gap:
                min_gap = primes[i + 1] - primes[i]
                result = [primes[i], primes[i + 1]]

        return result
