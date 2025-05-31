typedef struct {
    int* data;
    int front;
    int rear;
    int size;
    int capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->data = (int*)malloc(sizeof(int) * capacity);
    q->front = 0;
    q->rear = 0;
    q->size = 0;
    q->capacity = capacity;
    return q;
}

bool isEmpty(Queue* q) {
    return q->size == 0;
}

void enqueue(Queue* q, int value) {
    if (q->size == q->capacity) return;
    q->data[q->rear++] = value;
    q->size++;
}

int dequeue(Queue* q) {
    if (q->size == 0) return -1;
    int val = q->data[q->front++];
    q->size--;
    return val;
}

int snakesAndLadders(int** board, int boardSize, int* boardColSize) {
    int n = boardSize;
    int maxCell = n * n;
    bool* visited = (bool*)calloc(maxCell + 1, sizeof(bool));
    Queue* q = createQueue(maxCell + 1);
    
    enqueue(q, 1);
    visited[1] = true;
    
    int level = 0;

    while (!isEmpty(q)) {
        int size = q->size;
        for (int i = 0; i < size; ++i) {
            int curr = dequeue(q);
            if (curr == maxCell) {
                free(q->data); free(q); free(visited);
                return level;
            }

            for (int next = curr + 1; next <= curr + 6 && next <= maxCell; ++next) {
                int row = (next - 1) / n;
                int col = (next - 1) % n;
                if (row % 2 == 1)
                    col = n - 1 - col;
                row = n - 1 - row;

                int dest = board[row][col] == -1 ? next : board[row][col];

                if (!visited[dest]) {
                    visited[dest] = true;
                    enqueue(q, dest);
                }
            }
        }
        level++;
    }

    free(q->data); free(q); free(visited);
    return -1;
}
