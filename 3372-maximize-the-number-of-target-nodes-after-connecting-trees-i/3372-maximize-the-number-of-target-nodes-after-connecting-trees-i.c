/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define MAXN 1005
#define max(a,b) ((a) > (b) ? (a) : (b))

typedef struct Node {
    int val;
    struct Node* next;
} Node;

typedef struct {
    int u, parent;
} Pair;

// Adjacency list
Node* adj1[MAXN];
Node* adj2[MAXN];

// Add edge to the adjacency list
void add_edge(Node* adj[], int u, int v) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = v;
    node->next = adj[u];
    adj[u] = node;
}

// Breadth-First Search up to depth k
int BFS(int start, Node* adj[], int k) {
    Pair queue[MAXN * 2];
    int front = 0, back = 0;
    queue[back++] = (Pair){start, -1};
    int count = 0;

    while (front < back && k >= 0) {
        int size = back - front;
        count += size;

        for (int i = 0; i < size; i++) {
            Pair curr = queue[front++];
            int u = curr.u;
            int parent = curr.parent;
            for (Node* node = adj[u]; node != NULL; node = node->next) {
                int v = node->val;
                if (v != parent) {
                    queue[back++] = (Pair){v, u};
                }
            }
        }
        k--;
    }

    return count;
}

// Main function
int* maxTargetNodes(int** edges1, int edges1Size, int* edges1ColSize,
                    int** edges2, int edges2Size, int* edges2ColSize,
                    int k, int* returnSize) {
    // Reset adjacency lists
    memset(adj1, 0, sizeof(adj1));
    memset(adj2, 0, sizeof(adj2));

    int m = edges1Size + 1;
    int n = edges2Size + 1;

    // Build Tree 1 adjacency list
    for (int i = 0; i < edges1Size; i++) {
        int u = edges1[i][0];
        int v = edges1[i][1];
        add_edge(adj1, u, v);
        add_edge(adj1, v, u);
    }

    // Build Tree 2 adjacency list
    for (int i = 0; i < edges2Size; i++) {
        int u = edges2[i][0];
        int v = edges2[i][1];
        add_edge(adj2, u, v);
        add_edge(adj2, v, u);
    }

    // Best reachable nodes in Tree 2 within (k - 1) distance
    int best = 0;
    for (int i = 0; i < n; i++) {
        int connections = BFS(i, adj2, k - 1);
        best = max(best, connections);
    }

    // Result array for Tree 1 nodes
    int* res = (int*)malloc(sizeof(int) * m);
    for (int i = 0; i < m; i++) {
        int connections = BFS(i, adj1, k);
        res[i] = connections + best;
    }

    *returnSize = m;
    return res;
}
