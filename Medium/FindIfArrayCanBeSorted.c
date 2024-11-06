bool isChangable(int a, int b) {
    int acnt = 0;
    int bcnt = 0;

    for (; a != 0; a >>= 1)
        if (a & 1 == 1)
            acnt++;
    
    for (; b != 0; b >>= 1)
        if (b & 1 == 1)
            bcnt++;
    
    return acnt == bcnt;
}

void swapNums(int* nums, int lidx, int ridx) {
    int tmp = 0;
    tmp = nums[lidx];
    nums[lidx] = nums[ridx];
    nums[ridx] = tmp;

    return;
}

bool canSortArray(int* nums, int numsSize) {
    int size = numsSize;
    for (; size > 1; size--)
        for (int i = 0; i < numsSize - 1; i++)
            if (nums[i] > nums[i+1])
                if (isChangable(nums[i], nums[i+1]))
                    swapNums(nums, i, i+1);
                else
                    return false;
    return true;
}
