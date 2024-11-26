int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int ret = 0;
    int sret = 0;

    for (int i = 0; i < numsSize; i++)
        if (nums[i] == 0)
            ret = sret > ret ? sret : ret, sret = 0;
        else
            sret++;
    
    ret = sret > ret ? sret : ret;

    return ret;
}
