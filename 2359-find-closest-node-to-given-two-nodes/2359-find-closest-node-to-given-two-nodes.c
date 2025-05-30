typedef struct {
    int node;
    int type;
} QueueNode;

int closestMeetingNode(int* edges, int edgesSize, int node1, int node2) {
    int** dist = (int**)malloc(edgesSize * sizeof(int*));
    for (int i = 0; i < edgesSize; ++i) {
        dist[i] = (int*)malloc(2 * sizeof(int));
        dist[i][0] = -1;
        dist[i][1] = -1;
    }

    dist[node1][0] = 0;
    dist[node2][1] = 0;

    QueueNode* queue = (QueueNode*)malloc(2 * edgesSize * sizeof(QueueNode));
    int front = 0, back = 0;
    queue[back++] = (QueueNode){node1, 0};
    queue[back++] = (QueueNode){node2, 1};

    // BFS for both sources
    while (front < back) {
        QueueNode current = queue[front++];
        int curr = current.node;
        int type = current.type;
        int next = edges[curr];
        if (next != -1 && dist[next][type] == -1) {
            dist[next][type] = dist[curr][type] + 1;
            queue[back++] = (QueueNode){next, type};
        }
    }

    // Find the closest meeting node
    int meeting_point = -1;
    int meeting_distance = INT_MAX;
    for (int i = 0; i < edgesSize; ++i) {
        if (dist[i][0] != -1 && dist[i][1] != -1) {
            int maxDist = dist[i][0] > dist[i][1] ? dist[i][0] : dist[i][1];
            if (maxDist < meeting_distance) {
                meeting_distance = maxDist;
                meeting_point = i;
            }
        }
    }

    // Clean up
    for (int i = 0; i < edgesSize; ++i) {
        free(dist[i]);
    }
    free(dist);
    free(queue);

    return meeting_point;
}
