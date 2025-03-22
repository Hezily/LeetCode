class DSU {
public:
    vector<int> parent, size;
    
    DSU(int n) : parent(n), size(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int node) {
        return parent[node] == node ? node : parent[node] = find(parent[node]); // Path compression
    }
    
    void unionSet(int node1, int node2) {
        int root1 = find(node1);
        int root2 = find(node2);
        
        if (root1 == root2) return;
        
        if (size[root1] > size[root2]) {
            parent[root2] = root1;
            size[root1] += size[root2];
        } else {
            parent[root1] = root2;
            size[root2] += size[root1];
        }
    }
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        vector<int> edgeCount(n, 0);
        
        for (const auto& edge : edges) {
            dsu.unionSet(edge[0], edge[1]);
        }
        
        unordered_map<int, int> nodeCount;
        for (int i = 0; i < n; i++) {
            int root = dsu.find(i);
            nodeCount[root]++;
        }
        
        for (const auto& edge : edges) {
            int root = dsu.find(edge[0]);
            edgeCount[root]++;
        }
        
        int completeCount = 0;
        for (const auto& [root, count] : nodeCount) {
            int expectedEdges = (count * (count - 1)) / 2;
            if (edgeCount[root] == expectedEdges) {
                completeCount++;
            }
        }
        return completeCount;
    }
};