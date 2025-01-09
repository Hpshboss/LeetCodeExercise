int longestSubarray(int* nums, int numsSize) {
    int ret = 0;
    int lidx = 0;
    int ridx = 0;
    int delidx = -1;

    while (ridx < numsSize)
    {
        if (nums[ridx] == 0)
        {
            lidx = delidx + 1;
            delidx = ridx;
        }
        ret = ret > (ridx - lidx + 1) ? ret : (ridx - lidx + 1);
        ridx++;
    }
    ret--;
    return ret;
}
