#define BUFSIZE 3005
#define ISINRANGE(t, r) (t <= r && t >= r - 3000)

typedef struct {
    int head;
    int tail;
    int size;
    int* times;
} RecentCounter;


RecentCounter* recentCounterCreate() {
    RecentCounter* rc = malloc(sizeof(RecentCounter));
    rc->times = calloc(BUFSIZE, sizeof(int));
    rc->head = 0;
    rc->tail = 0;
    rc->size = BUFSIZE;
    return rc;
}

int recentCounterPing(RecentCounter* rc, int t) {
    static int ret = 0;
    if (rc->head == rc->tail)
        ret = 0;
    
    rc->times[rc->tail] = t;

    if ((rc->head - rc->tail + rc->size) % rc->size == 1)
        rc->head = (rc->head + 1) % rc->size;

    rc->tail = (rc->tail + 1) % rc->size;
    
    ret++;
    for (int i = rc->head; (rc->tail - i + rc->size) % rc->size >= 1; i = (i + 1) % rc->size)
    {
        if (!ISINRANGE(rc->times[i], t))
        {
            ret--;
            rc->head = (i + 1) % rc->size;
        }
    }
    return ret;
}

void recentCounterFree(RecentCounter* rc) {
    free(rc->times);
    free(rc);
    return;
}

/**
 * Your RecentCounter struct will be instantiated and called as such:
 * RecentCounter* obj = recentCounterCreate();
 * int param_1 = recentCounterPing(obj, t);
 
 * recentCounterFree(obj);
*/
