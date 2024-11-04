#define INTULIMIT 2147483647
#define INTLLIMIT -2147483648

#define NONIDX -1
#define TMPSIZE 3

int checkIdx(long val, long* arr, int arrSize) {
    for (int i = 0; i < arrSize; i++)
    {
        if (val == arr[i])
            return NONIDX;
        if (val > arr[i]) 
            return i;
    }
    return NONIDX;
}

void insertArr(long val, int idx, long* arr, int arrSize) {
    for (int i = arrSize-2; i >= idx; i--)
        arr[i+1] = arr[i];
    arr[idx] = val;
    return;
}

int thirdMax(int* nums, int numsSize) {
    int ret = 0;
    long tmp[TMPSIZE] = {INTLLIMIT-1, INTLLIMIT-1, INTLLIMIT-1}; // -2^31

    for (int i = 0; i < numsSize; i++)
    {   
        int idx = checkIdx((long)nums[i], tmp, TMPSIZE);
        if (idx == NONIDX)
            continue;
        insertArr((long)nums[i], idx, tmp, 3);
    }

    if (tmp[TMPSIZE-1] == INTLLIMIT-1)
        ret = (int) tmp[0];
    else
        ret = (int) tmp[TMPSIZE-1];

    return ret;
}
