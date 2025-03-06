
def check(nums, index) -> bool:
    size = len(nums) - 1
    
    if index >= size:  # If we reached the last index, return True
        return True

    first_element = nums[index]  # Get the jump length at current index

    if first_element == 0 and index != size:  # If stuck at zero before last index, return False
        return False

    for i in range(1, min(first_element + 1, len(nums) - index)):  # Ensure i is within bounds
        if check(nums, index + i):  # Recursive call to check next possible positions
            return True
    
    return False  # If no valid jumps found, return False

class Solution:
    def canJump(self, nums: List[int]) -> bool:
        return check(nums, 0)