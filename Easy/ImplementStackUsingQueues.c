typedef struct {
    int top;
    int* stack;
} MyStack;


MyStack* myStackCreate() {
    MyStack* ret = malloc(sizeof(MyStack));
    ret->stack = malloc(100 * sizeof(int));
    ret->top = 0;
    for (int i = 0; i < 100; i++) ret->stack[i] = 0;
    return ret;
}

void myStackPush(MyStack* obj, int x) {
    obj->stack[obj->top] = x;
    obj->top++;
    return;
}

int myStackPop(MyStack* obj) {
    obj->top--;
    return obj->stack[obj->top];
}

int myStackTop(MyStack* obj) {
    if (obj->top == 0) return NULL;
    return obj->stack[obj->top-1];
}

bool myStackEmpty(MyStack* obj) {
    if (obj->top == 0) return true;
    return false;
}

void myStackFree(MyStack* obj) {
    free(obj->stack);
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
