class Solution:
    def magnificentSets(self, n: int, edges: List[List[int]]) -> int:
        adj_list = [[] for _ in range(n)]
        for u, v in edges:
            adj_list[u - 1].append(v - 1)
            adj_list[v - 1].append(u - 1)
        
        # Bipartite check using DFS
        colors = [0] * n
        def is_bipartite(node, color):
            stack = [node]
            colors[node] = color
            while stack:
                curr = stack.pop()
                for neighbor in adj_list[curr]:
                    if colors[neighbor] == colors[curr]:
                        return False
                    if colors[neighbor] == 0:
                        colors[neighbor] = -colors[curr]
                        stack.append(neighbor)
            return True
        
        for node in range(n):
            if colors[node] == 0 and not is_bipartite(node, 1):
                return -1
        
        # Function to get longest path in the component
        def get_longest_length(node):
            queue = deque([node])
            visited = [False] * n
            visited[node] = True
            distance = 0
            
            while queue:
                for _ in range(len(queue)):
                    curr = queue.popleft()
                    for neighbor in adj_list[curr]:
                        if not visited[neighbor]:
                            visited[neighbor] = True
                            queue.append(neighbor)
                distance += 1
            return distance
        
        distances = [get_longest_length(node) for node in range(n)]
        
        # Calculate the number of groups
        def get_number_of_groups_for_component(node):
            max_groups = distances[node]
            visited[node] = True
            for neighbor in adj_list[node]:
                if not visited[neighbor]:
                    max_groups = max(max_groups, get_number_of_groups_for_component(neighbor))
            return max_groups
        
        max_number_of_groups = 0
        visited = [False] * n
        for node in range(n):
            if not visited[node]:
                max_number_of_groups += get_number_of_groups_for_component(node)
        
        return max_number_of_groups
