class Solution:
    def maxChunksToSorted(self, arr):
        sorted_arr = sorted(arr)
        sum_original = 0
        sum_sorted = 0
        count = 0

        for i in range(len(arr)):
            sum_original += arr[i]
            sum_sorted += sorted_arr[i]
            # If the cumulative sums are equal, we can form a chunk
            if sum_original == sum_sorted:
                count += 1

        return count

