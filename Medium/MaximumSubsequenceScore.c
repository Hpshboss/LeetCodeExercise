typedef struct {
    int *arr;
    int  size;
    int  capacity;
} MinHeap;

MinHeap* createHeap(int capacity) {
    MinHeap* heap = malloc(sizeof(MinHeap));
    heap->size     = 0;
    heap->capacity = capacity;
    heap->arr      = malloc(sizeof(int) * capacity);
    return heap;
}

void swap(int *a, int *b) {
    int tmp = *a; 
    *a = *b; 
    *b = tmp;
}

void heapifyDown(MinHeap* heap, int i) {
    int smallest = i;
    int left  = 2*i + 1;
    int right = 2*i + 2;

    if (left  < heap->size && heap->arr[left]  < heap->arr[smallest])
        smallest = left;
    if (right < heap->size && heap->arr[right] < heap->arr[smallest])
        smallest = right;
    if (smallest != i) {
        swap(&heap->arr[i], &heap->arr[smallest]);
        heapifyDown(heap, smallest);
    }
}

void heapifyUp(MinHeap* heap, int i) {
    int parent = (i - 1) / 2;
    if (i > 0 && heap->arr[i] < heap->arr[parent]) {
        swap(&heap->arr[i], &heap->arr[parent]);
        heapifyUp(heap, parent);
    }
}

void insertMinHeap(MinHeap* heap, int value) {
    if (heap->size == heap->capacity)
        return;
    heap->arr[heap->size++] = value;
    heapifyUp(heap, heap->size - 1);
}

int extractMin(MinHeap* heap) {
    if (heap->size <= 0) 
        return -1;
    int root = heap->arr[0];
    heap->arr[0] = heap->arr[--heap->size];
    heapifyDown(heap, 0);
    return root;
}

/*What i write is th below*/
struct pair {
    int val1;
    int val2;
};

int compare(const void* a, const void* b) {
    return (((struct pair*)b)->val2 - ((struct pair*)a)->val2);
}

long long maxScore(int* nums1, int nums1Size, int* nums2, int nums2Size, int k) {
    struct pair* pairs = malloc(nums1Size * sizeof(struct pair));
    MinHeap* heap = createHeap(k+1);
    long long ret = 0;
    long long sum1 = 0;
    int val1 = 0;
    int val2 = 0;

    for (int i = 0; i < nums1Size; i++)
    {
        pairs[i].val1 = nums1[i];
        pairs[i].val2 = nums2[i];
    }

    qsort(pairs, nums1Size, sizeof(struct pair), compare);

    for (int i = 0; i < nums1Size; i++)
    {
        val1 = pairs[i].val1;
        val2 = pairs[i].val2;
        insertMinHeap(heap, val1);
        sum1 += val1;

        if (heap->size > k)
            sum1 -= (long long) extractMin(heap);
        if (heap->size == k)
            ret = ret < sum1 * val2 ? sum1 * val2 : ret;
    }

    return ret;
}
