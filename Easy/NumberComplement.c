int findComplement(int num) {
    int ret = 0;
    int bitlen = 0;

    for (int i = 0; i < 31; i++)
        if (num & (1u << i))
            bitlen = i;

    for (int i = 0; i < bitlen; i++, num >>= 1)
        if (!(num & 1))
            ret += 1 << i;
    
    return ret;
}
