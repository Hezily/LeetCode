class Solution:
    def maxChunksToSorted(self, arr):
        max_so_far = float('-inf')
        count = 0
        
        for i in range(len(arr)):
            max_so_far = max(max_so_far, arr[i])
            if max_so_far == i:
                count += 1
        
        return count
