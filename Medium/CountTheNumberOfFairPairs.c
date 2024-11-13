int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

long long countFairPairs(int* nums, int numsSize, int lower, int upper) {
    long long singleret = 0;
    long long ret = 0;

    qsort(nums, numsSize, sizeof(int), compare);
    
    for (int i = 0; i < numsSize - 1; i++)
    {
        int lidx = i + 1;
        int ridx = numsSize - 1;
        printf("i=%d\n", i);
        if (nums[i] + nums[lidx] > upper)
            continue;
        
        while (nums[i] + nums[lidx] < lower)
        {
            if (lidx == ridx)
                break;
            else
                lidx++;
        }

        if (nums[i] + nums[ridx] < lower)
            continue;
        
        while (nums[i] + nums[ridx] > upper)
        {
            if (lidx == ridx)
                break;
            else
                ridx--;
        }
        if (ridx == lidx)
        {
            if (nums[i] + nums[ridx] > upper)
                continue;
            if (nums[i] + nums[ridx] < lower)
                continue;
        }
        ret += (ridx - lidx + 1);
    }
    return ret;
}
