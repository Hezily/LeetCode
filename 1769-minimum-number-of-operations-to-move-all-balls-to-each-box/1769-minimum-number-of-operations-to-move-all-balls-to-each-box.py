
class Solution:
    def minOperations(self, boxes: str) -> List[int]:
        n = len(boxes)
        left = [0] * n
        count = int(boxes[0])
        
        # Left pass
        for i in range(1, n):
            left[i] = left[i - 1] + count
            count += int(boxes[i])
        
        # Right pass
        count = int(boxes[n - 1])
        prev_right = 0
        for i in range(n - 2, -1, -1):
            cur_right = prev_right + count
            prev_right = cur_right
            left[i] += cur_right
            count += int(boxes[i])
        
        return left
