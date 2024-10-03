void moveZeroes(int* nums, int numsSize) {
    for (int i = numsSize - 1; i >= 0; i--)
    {
        if (nums[i] == 0)
        {
            for (int j = i; j < numsSize - 1; j++)
            {
                if (nums[j+1] == 0) break;

                int tmp = nums[j+1];
                nums[j+1] = nums[j];
                nums[j] = tmp;
            }
        }
    }
    return;
}
