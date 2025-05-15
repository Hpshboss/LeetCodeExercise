typedef struct {
    int idx;
    int val;
} idxval;

typedef struct {
    idxval *arr;
    int  size;
    int  capacity;
} MinHeap;

MinHeap* createHeap(int capacity) {
    MinHeap* heap = malloc(sizeof(MinHeap));
    heap->size     = 0;
    heap->capacity = capacity;
    heap->arr      = malloc(sizeof(idxval) * capacity);
    return heap;
}

void swap(idxval *a, idxval *b) {
    idxval tmp = *a; 
    *a = *b; 
    *b = tmp;
}

void heapifyDown(MinHeap* heap, int i) {
    int smallest = i;
    int left  = 2*i + 1;
    int right = 2*i + 2;

    if (left  < heap->size && heap->arr[left].val  < heap->arr[smallest].val)
        smallest = left;
    if (right < heap->size && heap->arr[right].val < heap->arr[smallest].val)
        smallest = right;
    if (smallest != i) {
        swap(&heap->arr[i], &heap->arr[smallest]);
        heapifyDown(heap, smallest);
    }
}

void heapifyUp(MinHeap* heap, int i) {
    int parent = (i - 1) / 2;
    if (i > 0 && heap->arr[i].val < heap->arr[parent].val) {
        swap(&heap->arr[i], &heap->arr[parent]);
        heapifyUp(heap, parent);
    }
}

void insertMinHeap(MinHeap* heap, idxval input) {
    if (heap->size == heap->capacity)
        return;
    heap->arr[heap->size++] = input;
    heapifyUp(heap, heap->size - 1);
}

idxval extractMinHeap(MinHeap* heap) {
    idxval invalid = { .idx = -1, .val = INT_MAX };
    if (heap->size <= 0) 
        return invalid;
    idxval root = heap->arr[0];
    heap->arr[0] = heap->arr[--heap->size];
    heapifyDown(heap, 0);
    return root;
}

long long totalCost(int* costs, int costsSize, int k, int candidates) {
    int lval = 0;
    int rval = 0;
    int lidx = candidates - 1;
    int ridx = costsSize - candidates;
    MinHeap* lheap = createHeap(candidates);
    MinHeap* rheap = createHeap(candidates);
    idxval tmp;
    long long ret = 0;

    if (lidx >= ridx)
        ridx = lidx + 1;
    
    // printf("lidx=%d, ridx=%d\n", lidx, ridx);
    for (int i = 0; i <= lidx; i++) 
        insertMinHeap(lheap, (idxval){ .idx = i, .val = costs[i] });

    for (int i = ridx; i < costsSize; i++)
        insertMinHeap(rheap, (idxval){ .idx = i, .val = costs[i] });
    
    while (k > 0)
    {
        lval = lheap->size != 0 ? lheap->arr[0].val : 0;
        rval = rheap->size != 0 ? rheap->arr[0].val : 0;

        if (lval == 0)
        {
            tmp = extractMinHeap(rheap);
        }
        else if (rval == 0)
        {
            tmp = extractMinHeap(lheap);
        }
        else
        {
            if (lval <= rval)
            {
                tmp = extractMinHeap(lheap);
                if (lidx + 1 < ridx)
                {
                    lidx++;
                    insertMinHeap(lheap, (idxval){ .idx = lidx, .val = costs[lidx] });
                }
            }
            else
            {
                tmp = extractMinHeap(rheap);
                if (lidx + 1 < ridx)
                {
                    ridx--;
                    insertMinHeap(rheap, (idxval){ .idx = ridx, .val = costs[ridx] });
                }
            }
        }
        
        ret += (long long) tmp.val;
        k--;
    }
    return ret;
}
