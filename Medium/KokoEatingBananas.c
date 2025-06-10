int ceilInt(int dividend, int divisor) {
    int ret = 0;

    if (dividend % divisor > 0)
    {
        ret = (dividend / divisor) + 1;
    }
    else
    {
        ret = dividend / divisor;
    }

    return ret;
}

int maxArray(const int* arr, int size) {
    if (size <= 0) return 0;

    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

int minEatingSpeed(int* piles, int pilesSize, int h) {
    int minsp = 0;
    int maxsp = maxArray(piles, pilesSize);
    int midsp = (minsp + maxsp) >> 1;
    long time = 0;
    int retsp = 1;
    
    while (maxsp - minsp > 1)
    {
        for (int i = 0; i < pilesSize; i++)
            time += ceilInt(piles[i], midsp);
            
        if (time > h)
            minsp = midsp;
        if (time <= h)
            maxsp = midsp;

        time = 0;
        midsp = (minsp + maxsp) >> 1;
    }
    retsp = maxsp;

    return retsp;
}
