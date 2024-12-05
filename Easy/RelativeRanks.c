/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int compare(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

int findIdx(int* arr, int arrSize, int val) { // arr must be desending
    int lidx = 0;
    int ridx = arrSize - 1;
    int midx = midx = (lidx + ridx) >> 1;

    while (midx > lidx)
    {
        if (arr[midx] == val)
            return midx;
        else if (arr[midx] < val)
            ridx = midx;
        else
            lidx = midx;
        midx = (lidx + ridx) >> 1;
    }

    if (arr[lidx] == val)
        return lidx;
    
    if (arr[ridx] == val)
        return ridx;
    
    return -1;
}

char** findRelativeRanks(int* score, int scoreSize, int* returnSize) {
    char** ret = malloc(scoreSize * sizeof(char*));
    int* scorecpy = malloc(scoreSize * sizeof(int));
    int idx = -1;

    *returnSize = scoreSize;

    for (int i = 0; i < scoreSize; i++)
        scorecpy[i] = score[i];
    
    qsort(scorecpy, scoreSize, sizeof(int), compare);

    for (int i = 0; i < scoreSize; i++)
    {
        idx = findIdx(scorecpy, scoreSize, score[i]);
        if (idx > 2)
            ret[i] = malloc(6 * sizeof(char)), sprintf(ret[i], "%d", idx + 1);
        else if (idx == 0)
            ret[i] = malloc(11 * sizeof(char)), sprintf(ret[i], "%s", "Gold Medal");
        else if (idx == 1)
            ret[i] = malloc(13 * sizeof(char)), sprintf(ret[i], "%s", "Silver Medal");
        else if (idx == 2)
            ret[i] = malloc(13 * sizeof(char)), sprintf(ret[i], "%s", "Bronze Medal");
    }

    free(scorecpy);
    return ret;
}
