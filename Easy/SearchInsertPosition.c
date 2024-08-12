int searchInsert(int* nums, int numsSize, int target) {
    if (nums[0] >= target) return 0;
    if (nums[numsSize - 1] < target) return numsSize;

    int lidx = 0, ridx = numsSize - 1;
    int midx = (lidx + ridx) >> 1;

    while ((ridx - lidx) > 1)
    {
        if (nums[midx] > target)
        {
            ridx = midx;
        }
        else if (nums[midx] < target)
        {
            lidx = midx;
        }
        else
        {
            return midx;
        }
        midx = (lidx + ridx) >> 1;
    }
    return lidx + 1;
}
