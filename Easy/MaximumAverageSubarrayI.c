double findMaxAverage(int* nums, int numsSize, int k) {
    double avg = 0;
    double maxavg = 0;
    int window = 0;

    for (int i = 0; i < k; i++)
        window += nums[i];

    maxavg = (double) window / (double) k;
    for (int i = k; i < numsSize; i++)
    {
        window += nums[i] - nums[i-k];
        avg = (double) window / (double) k;
        maxavg = maxavg > avg ? maxavg : avg;
    }

    return maxavg;
}
