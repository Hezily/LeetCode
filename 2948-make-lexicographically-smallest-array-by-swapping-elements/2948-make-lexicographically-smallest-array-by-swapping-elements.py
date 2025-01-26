class Solution:
    def lexicographicallySmallestArray(self, nums, limit):
        # Time Complexity: O(nlogn + 3n)
        n = len(nums)
        temp = nums[:]
        temp.sort()  # Sort the array to determine groups
        groups = []
        group_map = {}
        group_index = 0

        # Initialize the first group
        groups.append(deque())
        groups[group_index].append(temp[0])
        group_map[temp[0]] = group_index

        for i in range(1, n):
            # Create a new group if the current value exceeds the limit
            if temp[i] - groups[group_index][-1] > limit:
                group_index += 1
                groups.append(deque())
            
            group_map[temp[i]] = group_index
            groups[group_index].append(temp[i])

        # Replace elements in `nums` with the smallest lexicographical value
        for i in range(n):
            gi = group_map[nums[i]]
            nums[i] = groups[gi].popleft()

        return nums
