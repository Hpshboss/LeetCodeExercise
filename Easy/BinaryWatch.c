/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char* timeFormat(int hour, int minute, int* returnSize){ 
    char* ret = malloc(6 * sizeof(char));
    *returnSize = 0;
    
    for (int i = 0; i < 2; i++)
    {
        ret[*returnSize] = (char)(48 + minute % 10);
        minute /= 10;
        *returnSize = *returnSize + 1;
    }
    
    ret[*returnSize] = ':';
    *returnSize = *returnSize + 1;
    
    do {
        ret[*returnSize] = (char)(48 + hour % 10);
        hour /= 10;
        *returnSize = *returnSize + 1;
    } while (hour != 0);
    
    for (int i = 0; i < *returnSize / 2; i++)
    {
        char t = ret[i];
        ret[i] = ret[*returnSize-i-1];
        ret[*returnSize-i-1] = t;
    }
    
    ret[*returnSize] = '\0';
    *returnSize = *returnSize + 1;
    return ret;
}

int* countBits(int n) {
    int* ret = calloc(n+1, sizeof(int));
    int base = 2;

    if (n == 0) return ret;

    ret[1] = 1;
    if (n == 1) return ret;

    ret[2] = 1;
    for (int i = 3; i < n + 1; i++)
    {
        if (i == base << 1)
        {
            base = base << 1;
            ret[i] = 1;
        }
        else
        {
            ret[i] = ret[i - base] + 1;
        }
    }
    return ret;
}

char** readBinaryWatch(int turnedOn, int* returnSize) {
    int* numcnts = countBits(60);
    char** ret = malloc(720 * sizeof(char*));
    int* timeSize = malloc(sizeof(int));

    *returnSize = 0;

    for (int hourOn = 0; hourOn <= turnedOn; hourOn++)
    {
        for (int i = 0; i < 12; i++)
        {
            if (numcnts[i] == hourOn)
            {
                for (int j = 0; j < 60; j++)
                {
                    if (numcnts[j] == turnedOn - hourOn)
                    {
                        *timeSize = 0;
                        ret[*returnSize] = timeFormat(i, j, timeSize);
                        *returnSize = *returnSize + 1;
                    }
                }
            }
        }
    }
    free(numcnts);
    free(timeSize);
    return ret;
}
