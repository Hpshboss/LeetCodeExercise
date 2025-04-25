typedef struct {
    int* set;
    int firstIdx;
} SmallestInfiniteSet;


SmallestInfiniteSet* smallestInfiniteSetCreate() {
    SmallestInfiniteSet* ret = malloc(sizeof(SmallestInfiniteSet));
    ret->set = calloc(1001, sizeof(int)); // 0: exist; 1: empty
    ret->firstIdx = 0;

    return ret;
}

int smallestInfiniteSetPopSmallest(SmallestInfiniteSet* obj) {
    int ret = (obj->firstIdx) + 1;
    obj->set[obj->firstIdx] = 1;
    
    for (obj->firstIdx += 1; obj->set[obj->firstIdx] == 1; obj->firstIdx += 1)
        continue;
    
    return ret;
}

void smallestInfiniteSetAddBack(SmallestInfiniteSet* obj, int num) {
    int idx = num - 1;
    
    obj->set[idx] = 0;
    if (obj->firstIdx > idx)
        obj->firstIdx = idx;
    
    return;
}

void smallestInfiniteSetFree(SmallestInfiniteSet* obj) {
    free(obj);
}

/**
 * Your SmallestInfiniteSet struct will be instantiated and called as such:
 * SmallestInfiniteSet* obj = smallestInfiniteSetCreate();
 * int param_1 = smallestInfiniteSetPopSmallest(obj);
 
 * smallestInfiniteSetAddBack(obj, num);
 
 * smallestInfiniteSetFree(obj);
*/
