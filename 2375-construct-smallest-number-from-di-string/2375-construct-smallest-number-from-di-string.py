class Solution:
    def smallestNumber(self, pattern: str) -> str:
        n = len(pattern)
        used = [False] * 10
        result = []
        self.backtrack(pattern, 0, [0] * (n + 1), used, result)
        return "".join(map(str, result))

    def backtrack(self, pattern: str, index: int, num: list, used: list, result: list) -> bool:
        if index > len(pattern):
            result.extend(num)
            return True  # Found the valid lexicographically smallest number

        for digit in range(1, 10):
            if not used[digit] and (index == 0 or self.isValid(num[index - 1], digit, pattern[index - 1])):
                used[digit] = True
                num[index] = digit
                if self.backtrack(pattern, index + 1, num, used, result):
                    return True
                num[index] = 0
                used[digit] = False  # Backtrack
        return False

    def isValid(self, lastDigit: int, currentDigit: int, condition: str) -> bool:
        return (condition == 'I' and lastDigit < currentDigit) or (condition == 'D' and lastDigit > currentDigit)