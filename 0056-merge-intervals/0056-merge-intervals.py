class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        """
        Merge overlapping intervals.
        
        :param intervals: List of intervals [start, end]
        :return: List of merged intervals
        """
        if not intervals:
            return []
        
        # Step 1: Sort the intervals by start time
        intervals.sort(key=lambda x: x[0])
        
        # Step 2: Initialize the result with the first interval
        merged = [intervals[0]]
        
        # Step 3: Iterate through the intervals
        for current in intervals[1:]:
            previous = merged[-1]
            
            # If intervals overlap, merge them
            if current[0] <= previous[1]:
                previous[1] = max(previous[1], current[1])
            else:
                # If they don't overlap, add the current interval to merged
                merged.append(current)
        
        return merged
