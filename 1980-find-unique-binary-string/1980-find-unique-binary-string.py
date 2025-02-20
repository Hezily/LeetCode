class Solution:
    def findDifferentBinaryString(self, nums: list[str]) -> str:
        n = len(nums)
        res = []
        for i in range(n):
            ch = '1' if nums[i][i] == '0' else '0'
            res.append(ch)
        return "".join(res)
