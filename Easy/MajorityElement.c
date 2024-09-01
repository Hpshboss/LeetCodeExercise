int majorityElement(int* nums, int numsSize) {
    bool checked = false;
    int ret = 0, maxCnt = 0;.c
    for (int i = 0; i < (numsSize+1) / 2; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[j] == nums[i]) checked = true;
        }
        if (checked) { checked = false; continue; }
        int cnt = 0;
        for (int j = i; j < numsSize; j++)
        {
            if (nums[j] == nums[i]) cnt++;
        }
        if (cnt > maxCnt)
        {
            ret = nums[i];
            maxCnt = cnt;
            cnt = 0;
        }
    }
    return ret;
}
