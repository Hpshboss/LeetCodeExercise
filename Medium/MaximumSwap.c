int countDigits(int num) {
    int ret = 0;
    while (num != 0)
    {
        ret++;
        num /= 10;
    }
    return ret;
}

void swapDigits(int* nums, int l, int r) {
    int tmp = nums[l];
    nums[l] = nums[r];
    nums[r] = tmp;
    return;
}

int nums2num(int* nums, int numsSize) {
    int ret = 0;
    int base = 1;
    for (int i = 0; i < numsSize; i++)
    {
        ret += nums[numsSize-1-i] * base;
        base *= 10;
    }
    return ret;
}

int maximumSwap(int num) {
    int ret = 0;
    int idx_l = 0;
    int idx_r = 0;
    int val_l = 0;
    int val_r = 0;
    int digits = countDigits(num);
    int* nums = calloc(digits, sizeof(int));

    if (digits == 1) return ret = num;

    for (int i = 0; i < digits; i++)
    {
        nums[digits-1-i] = num % 10;
        num /= 10;
    }
    
    val_r = nums[idx_r];
    for (int i = 1; i < digits; i++)
    {
        if (nums[i] - nums[i-1] > 0)
        {
            break;
        }
        else
        {
            idx_r = i;
            val_r = nums[idx_r];
        }
    }

    for (int i = idx_r; i < digits; i++)
    {
        if (val_r == nums[i]) idx_r = i;
        if (val_r < nums[i])
        {
            idx_r = i;
            val_r = nums[i];
        }
    }
    
    val_l = nums[digits-1];
    for (int i = digits-1; i >= 0; i--)
    {
        if (i == idx_r)
        {
            idx_l = i;
            val_l = nums[i];
        }
        if (nums[i] < val_r) 
        {
            idx_l = i;
            val_l = nums[i];
        }
    }

    if (nums[idx_l] < nums[idx_r]) swapDigits(nums, idx_l, idx_r);
    ret = nums2num(nums, digits);
    
    free(nums);
    return ret;
}
