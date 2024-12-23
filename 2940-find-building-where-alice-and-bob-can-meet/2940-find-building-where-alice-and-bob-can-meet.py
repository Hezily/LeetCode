class Solution:
    def leftmostBuildingQueries(self, heights: List[int], queries: List[List[int]]) -> List[int]:
        from heapq import heappush, heappop
        
        n = len(heights)
        store_queries = [[] for _ in range(n)]
        max_index = []  # Min-heap equivalent of priority_queue in C++
        result = [-1] * len(queries)

        # Store the mappings for all queries in store_queries.
        for curr_query, (a, b) in enumerate(queries):
            if a < b and heights[a] < heights[b]:
                result[curr_query] = b
            elif a > b and heights[a] > heights[b]:
                result[curr_query] = a
            elif a == b:
                result[curr_query] = a
            else:
                store_queries[max(a, b)].append((max(heights[a], heights[b]), curr_query))

        for index in range(n):
            # If the heap's smallest value is less than the current height, it is an answer to the query.
            while max_index and max_index[0][0] < heights[index]:
                _, curr_query = heappop(max_index)
                result[curr_query] = index

            # Push the queries with their max heights into the heap.
            for max_height, curr_query in store_queries[index]:
                heappush(max_index, (max_height, curr_query))

        return result
   