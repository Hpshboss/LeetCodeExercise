int pivotIndex(int* nums, int numsSize) {
    int ret = -1;
    int lwin = 0;
    int rwin = 0;

    for (int i = 0; i < numsSize; i++)
        rwin += nums[i];
    
    rwin -= nums[0];
    if (lwin == rwin)
    {
        ret = 0;
        return ret;
    }

    for (int i = 1; i < numsSize; i++)
    {
        lwin += nums[i-1];
        rwin -= nums[i];
        if (lwin == rwin)
        {
            ret = i;
            break;
        }
    }

    return ret;
}
