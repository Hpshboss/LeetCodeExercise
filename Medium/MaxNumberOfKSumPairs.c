int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int maxOperations(int* nums, int numsSize, int k){
    int ret = 0;
    int lidx = 0;
    int ridx = numsSize - 1;
    int added = 0;
    int* snums = malloc(numsSize * sizeof(int));

    for (int i = 0; i < numsSize; i++)
        snums[i] = nums[i];

    qsort(snums, numsSize, sizeof(int), compare);

    while (lidx < ridx)
    {
        added = snums[lidx] + snums[ridx];
        
        if (added > k)
            ridx--;
        else if (added < k)
            lidx++;
        else // Equal
        {
            ret++;
            lidx++;
            ridx--;
        }
    }

    free(snums);
    
    return ret;
}
