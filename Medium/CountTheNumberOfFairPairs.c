int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

long long binSearch(int l, int r, int* nums, int target) {
    int m = 0;

    while (l <= r)
    {
        m = (l + r) >> 1;
        if (nums[m] >= target)
            r = m - 1;
        else
            l = m + 1;
    }

    return r;
}

long long countFairPairs(int* nums, int numsSize, int lower, int upper) {
    long long ret = 0;

    qsort(nums, numsSize, sizeof(int), compare);
    
    for (int i = 0; i < numsSize - 1; i++)
    {
        int lidx = i + 1;
        int ridx = numsSize - 1;
        int low = lower - nums[i];
        int up = upper - nums[i];
        
        ridx = binSearch(lidx, ridx, nums, up + 1);
        lidx = binSearch(lidx, ridx, nums, low);
        
        ret += (ridx - lidx);
    }
    return ret;
}
