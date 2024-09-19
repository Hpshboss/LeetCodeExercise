bool isPowerOfTwo(int n) {
    if (n < 1) return false;
    while (n != 1)
    {
        if (n & 1 == 1) return false;
        n = n >> 1;
    }
    return true;
}
