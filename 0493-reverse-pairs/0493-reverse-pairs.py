class Solution:
    def reversePairs(self, nums: list[int]) -> int:
        def merge_sort(start: int, end: int) -> int:
            if start >= end:
                return 0
            
            # Divide the array into two halves
            mid = (start + end) // 2
            
            # Count reverse pairs in left half, right half, and across the halves
            count = merge_sort(start, mid) + merge_sort(mid + 1, end)
            
            # Count reverse pairs across the two halves
            j = mid + 1
            for i in range(start, mid + 1):
                while j <= end and nums[i] > 2 * nums[j]:
                    j += 1
                count += (j - mid - 1)
            
            # Merge the two halves
            temp = []
            i, j = start, mid + 1
            while i <= mid and j <= end:
                if nums[i] <= nums[j]:
                    temp.append(nums[i])
                    i += 1
                else:
                    temp.append(nums[j])
                    j += 1
            while i <= mid:
                temp.append(nums[i])
                i += 1
            while j <= end:
                temp.append(nums[j])
                j += 1
            
            # Copy the sorted elements back into the original array
            nums[start:end + 1] = temp
            
            return count
        
        return merge_sort(0, len(nums) - 1)
