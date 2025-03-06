
class Solution:
    def jump(self, nums: List[int]) -> int:
        n = len(nums)
        jumps = 0
        current_end = 0
        farthest = 0

        for i in range(n - 1):  # We don't need to check the last index
            farthest = max(farthest, i + nums[i])

            if i == current_end:  # When we reach the boundary of the current jump
                jumps += 1
                current_end = farthest

        return jumps
