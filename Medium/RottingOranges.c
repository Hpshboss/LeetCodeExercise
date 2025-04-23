typedef struct {
    int pos[2];
    int time;
} celltime;

typedef struct {
    celltime *data;
    int front;
    int rear;
    int capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (!q) { perror("Memory allocation failed"); exit(EXIT_FAILURE); }
    q->data = (celltime*)malloc(sizeof(celltime) * capacity);
    if (!q->data) { perror("Memory allocation failed"); exit(EXIT_FAILURE); }
    q->front = 0;
    q->rear = 0;
    q->capacity = capacity;
    return q;
}

int isEmpty(Queue* q) {
    return (q->front == q->rear);
}

int isFull(Queue* q) {
    return ((q->rear + 1) % q->capacity == q->front);
}

void enqueue(Queue* q, celltime value) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    q->data[q->rear] = value;
    q->rear = (q->rear + 1) % q->capacity;
}

celltime dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        celltime errorVal = { {-1, -1}, -1 };
        return errorVal;
    }
    celltime ret = q->data[q->front];
    q->front = (q->front + 1) % q->capacity;
    return ret;
}

celltime peek(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        celltime errorVal = { {-1, -1}, -1 };
        return errorVal;
    }
    return q->data[q->front];
}

int size(Queue* q) {
    return (q->rear - q->front + q->capacity) % q->capacity;
}

void clear(Queue* q) {
    q->front = 0;
    q->rear = 0;
}

void freeQueue(Queue* q) {
    if (q) {
        free(q->data);
        free(q);
    }
}

int orangesRotting(int** grid, int gridSize, int* gridColSize) {
    Queue* timer = createQueue(100);
    celltime ct;
    celltime rotten;
    int initial = 0;
    int raxis = gridSize;
    int caxis = *gridColSize;
    int row = 0;
    int col = 0;
    int time = 0;
    int** pos = malloc(4 * sizeof(int*));
    int ret = 0;

    for (int i = 0; i < 4; i++)
        pos[i] = malloc(2 * sizeof(int));

    for (int i = 0; i < raxis; i++)
    {
        for (int j = 0; j < caxis; j++)
        {
            if (grid[i][j] == 2)
            {
                ct.pos[0] = i;
                ct.pos[1] = j;
                ct.time = 0;
                enqueue(timer, ct);
            }
        }
    }

    while (!isEmpty(timer))
    {
        rotten = dequeue(timer);

        row = rotten.pos[0];
        col = rotten.pos[1];
        time = rotten.time;

        for (int i = 0; i < 4; i++)
        {
            pos[i][0] = row + (i & 1 ? 0 : 1 - i); // 1, 0, -1, 0
            pos[i][1] = col + (i & 1 ? 2 - i : 0); // 0, 1, 0, -1
        }

        for (int i = 0; i < 4; i++)
        {
            if (pos[i][0] < 0 |
                pos[i][1] < 0 |
                pos[i][0] > raxis - 1 |
                pos[i][1] > caxis - 1)
            {
                continue;
            }
            
            if (grid[pos[i][0]][pos[i][1]] == 1)
            {
                grid[pos[i][0]][pos[i][1]] = 2;

                ct.pos[0] = pos[i][0];
                ct.pos[1] = pos[i][1];
                ct.time = time + 1;
                ret = time + 1;

                enqueue(timer, ct);
            }
        }
    }

    for (int i = 0; i < raxis; i++)
        for (int j = 0; j < caxis; j++)
            if (grid[i][j] == 1)
                return -1;

    return ret;
}
