int removeElement(int* nums, int numsSize, int val) {
    if (numsSize == 0) return 0;

    int lidx = 0;
    int ridx = numsSize - 1;

    while (lidx < ridx)
    {
        if (nums[lidx] == val)
        {
            int tmp = nums[lidx];
            nums[lidx] = nums[ridx];
            nums[ridx] = tmp;
            ridx--;
        }
        else
        {
            lidx++;
        }
    }

    return nums[lidx] == val ? lidx : lidx + 1;
}
