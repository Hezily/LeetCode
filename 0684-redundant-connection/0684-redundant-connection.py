class DisjointSet:
    def __init__(self, nodes):
        self.parent = list(range(nodes))
        self.size = [1] * nodes

    def find_root_parent(self, node):
        if self.parent[node] != node:
            self.parent[node] = self.find_root_parent(self.parent[node])  # Path compression
        return self.parent[node]

    def union_by_size(self, node1, node2):
        root1 = self.find_root_parent(node1)
        root2 = self.find_root_parent(node2)

        if root1 == root2:
            return False  # Cycle detected

        # Union by size
        if self.size[root1] < self.size[root2]:
            self.parent[root1] = root2
            self.size[root2] += self.size[root1]
        else:
            self.parent[root2] = root1
            self.size[root1] += self.size[root2]
        
        return True


class Solution:
    def findRedundantConnection(self, edges):
        total_nodes = len(edges)
        dsu = DisjointSet(total_nodes)

        for edge in edges:
            if not dsu.union_by_size(edge[0] - 1, edge[1] - 1):  # Convert to 0-based indexing
                return edge
        
        return []
