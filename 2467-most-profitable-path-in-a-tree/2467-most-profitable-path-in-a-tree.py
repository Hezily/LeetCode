
class Solution:
    def mostProfitablePath(self, edges: List[List[int]], bob: int, amount: List[int]) -> int:
        n = len(amount)
        tree = [[] for _ in range(n)]
        parent = [0] * n
        aliceDist = [-1] * n

        # Build the tree adjacency list
        for u, v in edges:
            tree[u].append(v)
            tree[v].append(u)

        # DFS to fill `parent` and `aliceDist`
        def dfs(u: int, prev: int, d: int) -> None:
            parent[u] = prev
            aliceDist[u] = d
            for v in tree[u]:
                if aliceDist[v] == -1:
                    dfs(v, u, d + 1)

        dfs(0, -1, 0)

        # Modify amount along Bob’s path
        u, bobDist = bob, 0
        while u != 0:
            if bobDist < aliceDist[u]:
                amount[u] = 0
            elif bobDist == aliceDist[u]:
                amount[u] //= 2
            u = parent[u]
            bobDist += 1

        # DFS to find the maximum profit path
        def getMoney(u: int, prev: int) -> int:
            if len(tree[u]) == 1 and tree[u][0] == prev:
                return amount[u]
            maxPath = -math.inf
            for v in tree[u]:
                if v != prev:
                    maxPath = max(maxPath, getMoney(v, u))
            return amount[u] + maxPath

        return getMoney(0, -1)
