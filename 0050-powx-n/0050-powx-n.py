class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n == 0:
            return 1.0  # Base case: x^0 = 1
        if n < 0:
            return 1 / self.myPow(x, -n)  # Handle negative powers

        # Optimize using exponentiation by squaring
        half = self.myPow(x, n // 2)
        if n % 2 == 0:  # If n is even
            return half * half
        else:  # If n is odd
            return half * half * x
