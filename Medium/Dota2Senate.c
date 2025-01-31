#define BUFSIZE 10000

typedef struct {
    int head;
    int tail;
    int size;
    int* buf;
} QBuf;

QBuf* queueBufferCreate() {
    QBuf* qbuf = malloc(sizeof(QBuf));
    qbuf->buf = calloc(BUFSIZE, sizeof(int));
    qbuf->head = 0;
    qbuf->tail = 0;
    qbuf->size = BUFSIZE;
    return qbuf;
}

int enqueue(QBuf* qbuf, int idx) {
    if (qbuf->size == (qbuf->tail - qbuf->head + qbuf->size) % qbuf->size)
        return -1;
    
    qbuf->buf[qbuf->tail] = idx;
    qbuf->tail = (qbuf->tail + 1) % BUFSIZE;

    return 0;
}

int dequeue(QBuf* qbuf) {
    int ret = 0;

    if ((qbuf->tail - qbuf->head + qbuf->size) % qbuf->size == 0)
        return 0;
    
    ret = qbuf->buf[qbuf->head];
    qbuf->head = (qbuf->head + 1) % BUFSIZE;

    return ret;
}

int frontQueue(QBuf* qbuf) {
    if ((qbuf->tail - qbuf->head + qbuf->size) % qbuf->size == 0)
        return 0;

    return qbuf->buf[qbuf->head];
}

int peekQueue(QBuf* qbuf) {
    if ((qbuf->tail - qbuf->head + qbuf->size) % qbuf->size == 0)
        return 0;

    return qbuf->buf[qbuf->tail-1];
}

bool isQueueEmpty(QBuf* qbuf) {
    if ((qbuf->tail - qbuf->head + qbuf->size) % qbuf->size == 0)
        return true;
    return false;
}

void queueBufferFree(QBuf* qbuf) {
    free(qbuf->buf);
    free(qbuf);
    return;
}

char* predictPartyVictory(char* senate) {
    char* ret = calloc(8, sizeof(char));
    int slen = strlen(senate);
    
    QBuf* rqbuf = queueBufferCreate();
    QBuf* dqbuf = queueBufferCreate();
    
    for (int i = 0; i < slen; i++)
    {
        if (senate[i] == 'R')
            enqueue(rqbuf, i);
        else // Represent Dire
            enqueue(dqbuf, i);
    }

    while (*ret == 0)
    {
        if (isQueueEmpty(rqbuf))
            strcpy(ret, "Dire");

        if (isQueueEmpty(dqbuf))
            strcpy(ret, "Radiant");
        
        if (frontQueue(rqbuf) < frontQueue(dqbuf))
        {
            dequeue(dqbuf);
            enqueue(rqbuf, dequeue(rqbuf) + slen);
        }
        else
        {
            dequeue(rqbuf);
            enqueue(dqbuf, dequeue(dqbuf) + slen);
        }
    }

    queueBufferFree(rqbuf);
    queueBufferFree(dqbuf);
    return ret;
}
