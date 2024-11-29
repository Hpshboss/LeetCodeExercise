int findPoisonedDuration(int* timeSeries, int timeSeriesSize, int duration) {
    int ret = 0;

    for (int i = 0; i < timeSeriesSize - 1; i++)
        if (timeSeries[i+1] - timeSeries[i] < duration)
            ret += timeSeries[i+1] - timeSeries[i];
        else
            ret += duration;

    ret += duration;

    return ret;
}
