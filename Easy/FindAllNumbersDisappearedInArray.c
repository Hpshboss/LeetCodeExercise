/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    int* cnts = calloc(numsSize, sizeof(int));
    int* ret = malloc(numsSize * sizeof(int));

    *returnSize = 0;
    
    for (int i = 0; i < numsSize; i++)
        cnts[nums[i]-1]++;
    
    for (int i = 0; i < numsSize; i++)
        if (cnts[i] == 0)
            ret[(*returnSize)++] = i + 1;

    free(cnts);
    return ret;
}
