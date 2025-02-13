class Solution:
    def minOperations(self, nums, k):
        pq = list(map(int, nums))
        heapq.heapify(pq)
        op = 0

        while len(pq) >= 2:
            x = heapq.heappop(pq)
            if x >= k:
                break
            y = heapq.heappop(pq)
            res = min(x, y) * 2 + max(x, y)
            heapq.heappush(pq, res)
            op += 1

        return op
