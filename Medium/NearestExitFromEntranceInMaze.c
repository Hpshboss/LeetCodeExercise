typedef struct {
    int pos[2];
    int step;
} cellcount;

typedef struct {
    cellcount *data;
    int front;
    int rear;
    int capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (!q) { perror("Memory allocation failed"); exit(EXIT_FAILURE); }
    q->data = (cellcount*)malloc(sizeof(cellcount) * capacity);
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

void enqueue(Queue* q, cellcount value) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    q->data[q->rear] = value;
    q->rear = (q->rear + 1) % q->capacity;
}

cellcount dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        cellcount errorVal = { {-1, -1}, -1 };
        return errorVal;
    }
    cellcount ret = q->data[q->front];
    q->front = (q->front + 1) % q->capacity;
    return ret;
}

cellcount peek(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        cellcount errorVal = { {-1, -1}, -1 };
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

int nearestExit(char** maze, int mazeSize, int* mazeColSize, int* entrance, int entranceSize)
{
    int ret = -1;
    int row = 0;
    int col = 0;
    int rborder = mazeSize;
    int cborder = *mazeColSize;
    int step = 0;

    char** edges = malloc(4 * sizeof(char*));

    Queue* counts = createQueue(mazeSize * (*mazeColSize));
    cellcount cc;

    // printf("The total size is %d\n", mazeSize * (*mazeColSize));

    for (int i = 0; i < 4; i++)
        edges[i] = malloc(2 * sizeof(char));

    cc.pos[0] = entrance[0];
    cc.pos[1] = entrance[1];
    cc.step = 0;

    maze[cc.pos[0]][cc.pos[1]] = '+';
    enqueue(counts, cc);

    while (!isEmpty(counts))
    {
        cc = dequeue(counts);
        
        row = cc.pos[0];
        col = cc.pos[1];
        step = cc.step;
        // printf("From %d, %d (%d) to:\n", row, col, step);

        for (int i = 0; i < 4; i++)
        {
            edges[i][0] = row + (i & 1 ? 0 : 1 - i); // 1, 0, -1, 0
            edges[i][1] = col + (i & 1 ? 2 - i : 0); // 0, 1, 0, -1
        }

        for (int i = 0; i < 4; i++)
        {
            if (edges[i][0] < 0 | 
                edges[i][1] < 0 | 
                edges[i][0] > rborder - 1 | 
                edges[i][1] > cborder - 1)
            {
                continue;
            }

            if (maze[edges[i][0]][edges[i][1]] != '+')
            {
                // printf("=> New Step: %d, %d (%d)\n", edges[i][0], edges[i][1], step + 1);
                cc.pos[0] = edges[i][0];
                cc.pos[1] = edges[i][1];
                cc.step = step + 1;
                maze[edges[i][0]][edges[i][1]] = '+';
                enqueue(counts, cc);
            }
            else
                continue;

            if (edges[i][0] == 0 | 
                edges[i][1] == 0 | 
                edges[i][0] == rborder - 1 | 
                edges[i][1] == cborder - 1)
            {
                // printf("=> First End Step: %d, %d (%d)\n", edges[i][0], edges[i][1], step + 1);
                freeQueue(counts);
                return step + 1;
            }
        }
    }
    freeQueue(counts);
    return -1;
}
