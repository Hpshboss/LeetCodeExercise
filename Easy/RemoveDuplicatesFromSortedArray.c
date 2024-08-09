int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    int cnt = 0;
    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i] != nums[i-1])
        {
            nums[cnt] = nums[i-1];
            cnt++;
        }
    }
    nums[cnt] = nums[numsSize-1];
    cnt++;

    return cnt;
}
