class Solution:
    def maxKDivisibleComponents(self, n, edges, values, k):
        # Create an adjacency list from edges
        adj_list = defaultdict(list)
        for node1, node2 in edges:
            adj_list[node1].append(node2)
            adj_list[node2].append(node1)
        
        # Counter for the number of k-divisible components
        component_count = [0]
        
        def dfs(current_node, parent_node):
            total_sum = 0
            for neighbor_node in adj_list[current_node]:
                if neighbor_node != parent_node:
                    # Recursively calculate the sum for subtrees
                    total_sum += dfs(neighbor_node, current_node)
            total_sum += values[current_node]
            
            # Check if the sum of the subtree is divisible by k
            if total_sum % k == 0:
                component_count[0] += 1
                return 0  # Reset sum after forming a component
            
            return total_sum
        
        # Start DFS from node 0 with no parent
        dfs(0, -1)
        return component_count[0]
