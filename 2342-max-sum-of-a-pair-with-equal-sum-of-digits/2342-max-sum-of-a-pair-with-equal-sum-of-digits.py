class Solution:
    def getDigitSum(self, num: int) -> int:
        digit_sum = 0
        while num > 0:
            digit_sum += num % 10
            num //= 10
        return digit_sum

    def maximumSum(self, nums: list[int]) -> int:
        digit_sum_map = [0] * 82  # Since max digit sum can be at most 81
        ans = -1

        for num in nums:
            digit_sum = self.getDigitSum(num)
            if digit_sum_map[digit_sum] > 0:
                prev_num = digit_sum_map[digit_sum]
                ans = max(ans, prev_num + num)
                digit_sum_map[digit_sum] = max(prev_num, num)
            else:
                digit_sum_map[digit_sum] = num

        return ans
