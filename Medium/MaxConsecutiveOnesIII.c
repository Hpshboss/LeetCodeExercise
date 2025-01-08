/**
 * RingBuffer structure holding:
 *  - A dynamically allocated array (buffer)
 *  - Head index, pointing to the next position to write
 *  - Tail index, pointing to the next position to read
 *  - Size, the total capacity of the buffer
 */
typedef struct {
    int* buffer;
    int head;
    int tail;
    int size;
} RingBuffer;

/**
 * @brief Initialize the Ring Buffer with the specified size.
 *
 * @param rb   Pointer to the RingBuffer structure.
 * @param size The size (capacity) of the Ring Buffer.
 * @return true if allocation succeeds, otherwise false.
 */
bool RingBuffer_Init(RingBuffer* rb, int size) {
    rb->buffer = (int*)malloc(sizeof(int) * size);
    if (rb->buffer == NULL) {
        // Memory allocation failed
        return false;
    }
    rb->head = 0;
    rb->tail = 0;
    rb->size = size;
    return true;
}

/**
 * @brief Free the allocated memory used by the Ring Buffer.
 *
 * @param rb Pointer to the RingBuffer structure.
 */
void RingBuffer_Destroy(RingBuffer* rb) {
    free(rb->buffer);
    rb->buffer = NULL;
    rb->head = 0;
    rb->tail = 0;
    rb->size = 0;
}

/**
 * @brief Check if the Ring Buffer is empty.
 *
 * @param rb Pointer to the RingBuffer structure.
 * @return true if the buffer is empty, otherwise false.
 */
bool RingBuffer_IsEmpty(const RingBuffer* rb) {
    return (rb->head == rb->tail);
}

/**
 * @brief Check if the Ring Buffer is full.
 *
 * In this design, 'head' points to the next position to write.
 * If (head + 1) % size == tail, the buffer is considered full.
 *
 * @param rb Pointer to the RingBuffer structure.
 * @return true if the buffer is full, otherwise false.
 */
bool RingBuffer_IsFull(const RingBuffer* rb) {
    return ((rb->head + 1) % rb->size == rb->tail);
}

/**
 * @brief Write data into the Ring Buffer.
 *
 * @param rb   Pointer to the RingBuffer structure.
 * @param data The data to be written.
 * @return true if the write is successful, false if the buffer is full.
 */
bool RingBuffer_Write(RingBuffer* rb, int data) {
    if (RingBuffer_IsFull(rb)) {
        // Buffer is full, cannot write
        return false;
    }
    rb->buffer[rb->head] = data;
    rb->head = (rb->head + 1) % rb->size;
    return true;
}

/**
 * @brief Read data from the Ring Buffer.
 *
 * @param rb   Pointer to the RingBuffer structure.
 * @param data Pointer to the variable where the read value will be stored.
 * @return true if the read is successful, false if the buffer is empty.
 */
bool RingBuffer_Read(RingBuffer* rb, int* data) {
    if (RingBuffer_IsEmpty(rb)) {
        // Buffer is empty, cannot read
        return false;
    }
    *data = rb->buffer[rb->tail];
    rb->tail = (rb->tail + 1) % rb->size;
    return true;
}

int RingBuffer_GetCount(const RingBuffer* rb) {
    return (rb->head - rb->tail + rb->size) % rb->size;
}

int longestOnes(int* nums, int numsSize, int k) {
    int ret = 0;
    int lidx = 0;
    int ridx = 0;
    RingBuffer kidxs;
    RingBuffer_Init(&kidxs, k+1);

    while (ridx < numsSize)
    {
        if (nums[ridx] == 0)
        {
            if (k > 0)
                if (RingBuffer_GetCount(&kidxs) < k)
                {
                    RingBuffer_Write(&kidxs, ridx);
                }
                else
                {
                    RingBuffer_Read(&kidxs, &lidx);
                    lidx++;
                    RingBuffer_Write(&kidxs, ridx);
                }
            else
                lidx = ridx + 1;
        }
        // printf("cnt=%d; lidx=%d; ridx=%d\n", RingBuffer_GetCount(&kidxs), lidx, ridx);
        ret = ret > (ridx - lidx + 1) ? ret : (ridx - lidx + 1);
        ridx++;
    }
    RingBuffer_Destroy(&kidxs);
    return ret;
}
