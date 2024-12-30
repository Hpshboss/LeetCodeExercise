int largestAltitude(int* gain, int gainSize) {
    int ret = 0;
    int alt = 0;

    for (int i = 0; i < gainSize; i++)
    {
        alt += gain[i];
        if (alt > ret)
            ret = alt;
    }

    return ret;
}
