class DSU {
    vector<int> rank, parent;
public:
    DSU(int n) {
        rank.resize(n, 0);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = find(parent[node]);
    }
    
    void unionSets(int node1, int node2) {
        int rootParent1 = find(node1);
        int rootParent2 = find(node2);
        if (rootParent1 == rootParent2) {
            return;
        }
        if (rank[rootParent1] < rank[rootParent2]) {
            parent[rootParent1] = rootParent2;
        } else if (rank[rootParent2] < rank[rootParent1]) {
            parent[rootParent2] = rootParent1;
        } else {
            parent[rootParent2] = rootParent1;
            rank[rootParent1]++;
        }
    }
};

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        DSU dsu(n);
        for (auto& edge : edges) {
            dsu.unionSets(edge[0], edge[1]);
        }
        
        vector<int> compCost(n, INT_MAX);
        for (auto& edge : edges) {
            int rootParent = dsu.find(edge[0]);
            compCost[rootParent] &= edge[2];
        }
        
        int m = query.size();
        vector<int> res(m);
        for (int i = 0; i < m; i++) {
            int rootParent1 = dsu.find(query[i][0]);
            int rootParent2 = dsu.find(query[i][1]);
            if (rootParent1 != rootParent2) {
                res[i] = -1;
            } else {
                res[i] = compCost[rootParent1];
            }
        }
        return res;
    }
};