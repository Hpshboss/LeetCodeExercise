typedef struct {
    int front, rear, size;
    unsigned int capacity;
    int* arr;
} MyQueue;

typedef struct {
    MyQueue* q;
} MyStack;

MyQueue* CreateQueue(unsigned int capacity)
{
    MyQueue* ret = malloc(sizeof(MyQueue));
    ret->front = 0;
    ret->size = 0;

    ret->rear = capacity - 1;
    ret->capacity = capacity;

    ret->arr = malloc(ret->capacity * sizeof(int));

    return ret;
}

bool isQueueFull(MyQueue* queue)
{
    return (queue->size == queue->capacity);
}

void enQueue(MyQueue* queue, int val)
{
    if (isQueueFull(queue)) return;

    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->arr[queue->rear] = val;
    queue->size = queue->size + 1;
    return;
}

bool isQueueEmpty(MyQueue* queue)
{
    return queue->size == 0 ? true : false;
}

int deQueue(MyQueue* queue)
{
    if (isQueueEmpty(queue)) return NULL;
    int val = 0;

    queue->size = queue->size - 1;
    val = queue->arr[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    return val;     
}

MyStack* myStackCreate() {
    MyStack* ret = malloc(sizeof(MyStack));
    ret->q = CreateQueue(100);
    return ret;
}

void myStackPush(MyStack* obj, int x) {
    enQueue(obj->q, x);
    return;
}

int myStackPop(MyStack* obj) {
    int val = obj->q->arr[obj->q->rear];
    for (int i = 0; i < obj->q->size - 1; i++) enQueue(obj->q, deQueue(obj->q));
    deQueue(obj->q);
    return val;
}

int myStackTop(MyStack* obj) {
    if (obj->q->size == 0) return NULL;
    return obj->q->arr[obj->q->rear];
}

bool myStackEmpty(MyStack* obj) {
    if (obj->q->size == 0) return true;
    return false;
}

void myStackFree(MyStack* obj) {
    free(obj);
    return;
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/
/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/
