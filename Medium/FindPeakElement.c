int findPeakElement(int* nums, int numsSize) {
    int lidx = 0;
    int ridx = numsSize-1;
    int midx = (lidx + ridx) >> 1;
    int retidx = 0;

    while (ridx - lidx > 1)
    {
        if (midx == 0)
            break;

        if (nums[midx] < nums[midx+1])
        {
            lidx = midx;
        }
        else if (nums[midx] < nums[midx-1])
        {
            ridx = midx;
        }
        else
            break;  // Slope is 0
        
        midx = (lidx + ridx) >> 1;
    }

    if (nums[midx] > nums[ridx])
    {
        retidx = midx;
    }
    else
    {
        retidx = ridx;
    }
    return retidx;
}
