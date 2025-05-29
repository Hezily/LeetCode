/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct {
    int node;
    int parent;
} Pair;

// Simple queue for BFS
typedef struct {
    Pair* data;
    int front, rear;
    int capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue* q = malloc(sizeof(Queue));
    q->data = malloc(sizeof(Pair) * capacity);
    q->front = q->rear = 0;
    q->capacity = capacity;
    return q;
}

void enqueue(Queue* q, int node, int parent) {
    q->data[q->rear++] = (Pair){node, parent};
}

Pair dequeue(Queue* q) {
    return q->data[q->front++];
}

bool isEmpty(Queue* q) {
    return q->front == q->rear;
}

void freeQueue(Queue* q) {
    free(q->data);
    free(q);
}

int bfs(int start, int** adj, int* adjSize, int n, bool* included) {
    bool* visited = calloc(n, sizeof(bool));
    Queue* q = createQueue(2 * n);  // Safe size
    enqueue(q, start, -1);
    int level = 0, count = 0;

    while (!isEmpty(q)) {
        int size = q->rear - q->front;
        if (level % 2 == 0) count += size;

        for (int i = 0; i < size; ++i) {
            Pair p = dequeue(q);
            int curr = p.node, parent = p.parent;
            visited[curr] = true;
            if (included && level % 2 == 0) included[curr] = true;

            for (int j = 0; j < adjSize[curr]; ++j) {
                int v = adj[curr][j];
                if (v != parent && !visited[v]) {
                    enqueue(q, v, curr);
                }
            }
        }
        level++;
    }

    free(visited);
    freeQueue(q);
    return count;
}

int* maxTargetNodes(int** edges1, int edges1Size, int* edges1ColSize,
                    int** edges2, int edges2Size, int* edges2ColSize, int* returnSize) {
    int n1 = edges1Size + 1;
    int n2 = edges2Size + 1;

    // Step 1: Create adjacency lists with dynamic edge storage
    int** adj1 = calloc(n1, sizeof(int*));
    int* adj1Size = calloc(n1, sizeof(int));
    int** adj2 = calloc(n2, sizeof(int*));
    int* adj2Size = calloc(n2, sizeof(int));

    // Count degrees first
    int* deg1 = calloc(n1, sizeof(int));
    int* deg2 = calloc(n2, sizeof(int));
    for (int i = 0; i < edges1Size; ++i) {
        deg1[edges1[i][0]]++;
        deg1[edges1[i][1]]++;
    }
    for (int i = 0; i < edges2Size; ++i) {
        deg2[edges2[i][0]]++;
        deg2[edges2[i][1]]++;
    }

    // Allocate only needed size
    for (int i = 0; i < n1; ++i) adj1[i] = malloc(deg1[i] * sizeof(int));
    for (int i = 0; i < n2; ++i) adj2[i] = malloc(deg2[i] * sizeof(int));

    // Fill adjacency lists
    for (int i = 0; i < edges1Size; ++i) {
        int u = edges1[i][0], v = edges1[i][1];
        adj1[u][adj1Size[u]++] = v;
        adj1[v][adj1Size[v]++] = u;
    }
    for (int i = 0; i < edges2Size; ++i) {
        int u = edges2[i][0], v = edges2[i][1];
        adj2[u][adj2Size[u]++] = v;
        adj2[v][adj2Size[v]++] = u;
    }

    // Step 2: Analyze tree2
    int even2 = bfs(0, adj2, adj2Size, n2, NULL);
    int best2 = (even2 > (n2 - even2)) ? even2 : (n2 - even2);

    // Step 3: Mark even-level nodes in tree1
    bool* included = calloc(n1, sizeof(bool));
    int even1 = bfs(0, adj1, adj1Size, n1, included);

    // Step 4: Compute result
    int* result = malloc(n1 * sizeof(int));
    for (int i = 0; i < n1; ++i) {
        result[i] = (included[i] ? even1 : (n1 - even1)) + best2;
    }

    *returnSize = n1;

    // Cleanup
    for (int i = 0; i < n1; ++i) free(adj1[i]);
    for (int i = 0; i < n2; ++i) free(adj2[i]);
    free(adj1); free(adj1Size); free(deg1);
    free(adj2); free(adj2Size); free(deg2);
    free(included);

    return result;
}
