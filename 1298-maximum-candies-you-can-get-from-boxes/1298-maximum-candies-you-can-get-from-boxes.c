
int maxCandies(
    int* status, int statusSize,
    int* candies, int candiesSize,
    int** keys, int keysSize, int* keysColSize,
    int** containedBoxes, int containedBoxesSize, int* containedBoxesColSize,
    int* initialBoxes, int initialBoxesSize
) {
    int total = 0;

    // Visited arrays
    int* used = (int*)calloc(statusSize, sizeof(int));
    int* hasBox = (int*)calloc(statusSize, sizeof(int));
    int* inQueue = (int*)calloc(statusSize, sizeof(int));

    // Queue for BFS
    int* queue = (int*)malloc(sizeof(int) * 1000);
    int front = 0, rear = 0;

    for (int i = 0; i < initialBoxesSize; i++) {
        queue[rear++] = initialBoxes[i];
        hasBox[initialBoxes[i]] = 1;
    }

    int changed = 1;
    while (changed) {
        changed = 0;
        front = 0;
        while (front < rear) {
            int box = queue[front++];
            if (used[box]) continue;
            if (!status[box]) continue;

            // Mark as used
            used[box] = 1;
            total += candies[box];
            changed = 1;

            // Use keys in this box
            for (int i = 0; i < keysColSize[box]; i++) {
                int key = keys[box][i];
                if (!status[key]) {
                    status[key] = 1;
                    if (hasBox[key] && !used[key]) {
                        queue[rear++] = key;
                    }
                }
            }

            // Add contained boxes to queue
            for (int i = 0; i < containedBoxesColSize[box]; i++) {
                int nextBox = containedBoxes[box][i];
                if (!hasBox[nextBox]) {
                    queue[rear++] = nextBox;
                    hasBox[nextBox] = 1;
                }
            }
        }
    }

    free(used);
    free(hasBox);
    free(inQueue);
    free(queue);
    return total;
}
