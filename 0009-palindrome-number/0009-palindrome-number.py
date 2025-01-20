class Solution:
    def isPalindrome(self, x: int) -> bool:
        # Step 1: Negative numbers are not palindromes
        if x < 0:
            return False
        
        # Step 2: Reverse the number and compare it with the original
        original = x
        reversed_num = 0
        
        while x > 0:
            # Extract the last digit
            digit = x % 10
            # Append the digit to the reversed number
            reversed_num = reversed_num * 10 + digit
            # Remove the last digit from x
            x //= 10
        
        # Step 3: Check if the original number equals the reversed number
        return original == reversed_num
