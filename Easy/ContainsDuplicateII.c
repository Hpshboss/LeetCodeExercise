int cmp(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    if (k == 0) return false;
    int* idx = malloc(10000 * sizeof(int));
    int idxSize = 0;
    int* orig = malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) orig[i] = nums[i];
    
    qsort(nums, numsSize, sizeof(int), cmp);

    for (int i = 0; i < numsSize - 1; i++)
    {
        if (nums[i] == nums[i+1])
        {
            for (int j = 0; j < numsSize; j++)
            {
                if (orig[j] == nums[i])
                {
                    *idx = j; idx++; idxSize++;
                }
            }
            idx -= idxSize;
            for (int j = 0; j < idxSize; j++)
            {
                for (int jj = j+1; jj < idxSize; jj++)
                {
                    if (abs(idx[j] - idx[jj]) <= k) return true;
                }
            }
            idxSize = 0;
        }
    }

    return false;
}
