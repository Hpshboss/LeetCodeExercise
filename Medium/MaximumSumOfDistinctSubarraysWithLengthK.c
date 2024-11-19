long long sumRange(int* nums, int numsSize, int idx, int range){
    long long ret = 0;

    for (int i = idx; i < idx + range; i++)
        ret += nums[i];
    
    return ret;
}

int isDuplicate(int* nums, int numsSize, int idx, int range) {
    int ret = -1;
    bool up = true;
    bool down = true;
    
    if (idx + range > numsSize)
        return -2;
    
    for (int i = idx; i < idx + range - 1; i++)
        for (int j = i + 1; j < idx + range; j++)
        {
            if (nums[i] == nums[j])
            {
                ret = i;
                return ret;
            }

            int tmp = nums[j] - nums[j-1];
            if (tmp < 0)
                up = false;
            else if (tmp > 0)
                down = false;
            else
                up = false, down = false;

            if (j == idx + range - 1)
            {
                if (up == true)
                    return -1;
                if (down == true)
                    return -1;
            }
        }

    return ret;
}

long long maximumSubarraySum(int* nums, int numsSize, int k) {
    long long ret = 0;
    long long sret = 0; // single ret

    sret = sumRange(nums, numsSize, 0, k);
    if (isDuplicate(nums, numsSize, 0, k) == -1)
        ret = sret;

    for (int i = k; i < numsSize; i++)
    {
        sret += (nums[i] - nums[i-k]);
        int tmp = isDuplicate(nums, numsSize, i-k+1, k);
        if (tmp == -1)
            ret = sret > ret ? sret : ret;
        else
        {
            i = tmp + k - 1;
            if (i >= numsSize - 1)
                break;
            sret = sumRange(nums, numsSize, i-k+1, k);
        }
    }

    return ret;
}
