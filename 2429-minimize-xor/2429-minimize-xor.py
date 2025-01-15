class Solution:
    def minimizeXor(self, num1: int, num2: int) -> int:
        # Find the number of set bits in num2
        set_bits = bin(num2).count('1')
        bit = 31
        res = 0
        
        # Set the bits in `res` from the highest bit in `num1`
        while bit >= 0 and set_bits > 0:
            if (num1 & (1 << bit)) != 0:
                res |= (1 << bit)
                set_bits -= 1
            bit -= 1
        
        bit = 0
        # Set the remaining bits from the lowest bit
        while set_bits > 0 and bit <= 32:
            if (num1 & (1 << bit)) == 0:
                res |= (1 << bit)
                set_bits -= 1
            bit += 1
        
        return res
