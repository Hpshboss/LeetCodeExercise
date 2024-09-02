uint32_t reverseBits(uint32_t n) {
    uint32_t ret = 0;
    uint32_t digiVal = 2147483648; // 2^31
    for (int i = 0; i < 32; i++)
    {
        ret += (n % 2) * digiVal;
        digiVal = digiVal / 2;
        n = n >> 1;
    }
    return ret;
}
