bool increasingTriplet(int* nums, int numsSize) {
    int fnum = nums[0];
    int snum = INT_MAX;

    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i] > snum)
            return true;
        
        if (nums[i] > fnum)
            snum = nums[i];
        else
            fnum = nums[i];
    }
    return false;
}
