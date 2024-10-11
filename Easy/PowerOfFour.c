bool isPowerOfFour(int n) {
    if (n <= 0) return false;

    while (!(n & 3)) n >>= 2;

    return n == 1 ? true : false;
}
