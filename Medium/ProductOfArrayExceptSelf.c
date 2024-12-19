/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int cntzero = 0;
    int* ret;
    int allpro = 1;

    *returnSize = numsSize;

    for (int i = 0; i < numsSize; i++)
        if (nums[i] == 0)
            cntzero++;
        else
            allpro *= nums[i];

    
    if (cntzero > 1)
    {
        ret = calloc(numsSize, sizeof(int));
        return ret;
    }
    else if (cntzero > 0)
    {
        ret = calloc(numsSize, sizeof(int));
        for (int i = 0; i < numsSize; i++)
            if (nums[i] == 0)
                ret[i] = allpro;
        return ret;
    }

    ret = malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++)
        ret[i] = allpro / nums[i];

    return ret;
}
