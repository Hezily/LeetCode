class Solution:
    def eventualSafeNodes(self, graph):
        # Helper function for DFS
        def dfs(node, graph, memo):
            if node in memo:
                return memo[node]
            
            # Mark the node as currently being visited
            memo[node] = False
            
            for neighbor in graph[node]:
                if not dfs(neighbor, graph, memo):
                    return False
            
            # Mark the node as safe
            memo[node] = True
            return True

        n = len(graph)
        memo = {}
        result = []

        for i in range(n):
            if dfs(i, graph, memo):
                result.append(i)

        return result
