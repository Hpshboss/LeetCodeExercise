int cmpfunc (const void * a, const void * b)
{
   return (*(int*)a - *(int*)b);
}

int missingNumber(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    for (int i = 0; i < numsSize - 1; i++) 
        if (nums[i+1] - nums[i] > 1)
            return nums[i] + 1;
    return nums[0] != 0 ? 0 : numsSize;
}
