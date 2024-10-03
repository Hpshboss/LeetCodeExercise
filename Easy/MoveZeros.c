void moveZeroes(int* nums, int numsSize) {
    int* nonZeros = calloc(numsSize, sizeof(int));
    int* sp = nonZeros;

    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] != 0)
        {
            *nonZeros = nums[i];
            nonZeros++;
        }
    }
    nonZeros = sp;
    for (int i = 0; i < numsSize; i++) nums[i] = nonZeros[i];
    return;
}
