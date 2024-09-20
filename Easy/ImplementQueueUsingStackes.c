typedef struct {
    int top;
    int* stk;
} MyStack;

MyStack* myStack() {
    MyStack* ret = malloc(sizeof(MyStack));
    ret->top = 0;
    ret->stk = malloc(100 * sizeof(int));
    return ret;
}

void myStackPush(MyStack* obj, int x) {
    obj->top += 1;
    obj->stk[obj->top - 1] = x;
    return;
}

int myStackPop(MyStack* obj) {
    if (obj->top == 0) return NULL;
    obj->top -= 1;
    return obj->stk[obj->top];
}

int myStackTop(MyStack* obj) {
    return obj->stk[obj->top - 1];
}

bool myStackEmpty(MyStack* obj) {
    return obj->top == 0;
}

void myStackFree(MyStack* obj) {
    free(obj->stk);
    free(obj);
    return;
}

typedef struct {
    MyStack** stk;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* ret = malloc(sizeof(MyQueue));
    ret->stk = malloc(2 * sizeof(MyStack*));
    for (int i = 0; i < 2; i++)
    {
        ret->stk[i] = myStack();
    }
    return ret;
}

void myQueuePush(MyQueue* obj, int x) {
    myStackPush(obj->stk[0], x);
    return;
}

int myQueuePop(MyQueue* obj) {
    for (int i = 0; i < obj->stk[0]->top; i++) {
        obj->stk[1]->stk[i] = obj->stk[0]->stk[obj->stk[0]->top - i - 1];
    }
    obj->stk[1]->top = obj->stk[0]->top;
    int ret = myStackPop(obj->stk[1]);
    for (int i = 0; i < obj->stk[1]->top; i++) {
        obj->stk[0]->stk[i] = obj->stk[1]->stk[obj->stk[1]->top - i - 1];
    }
    obj->stk[0]->top = obj->stk[1]->top;
    return ret;
}

int myQueuePeek(MyQueue* obj) {
    if (obj->stk[0]->top == 0) return NULL;
    return obj->stk[0]->stk[0];
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->stk[0]->top == 0;
}

void myQueueFree(MyQueue* obj) {
    for (int i = 0; i < 2; i++) {
        myStackFree(obj->stk[i]);
    }
    free(obj->stk);
    free(obj);
    return;
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/
