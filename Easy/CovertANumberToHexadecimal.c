char singleToHex(int val) {
    char* retp = calloc(2, sizeof(char));
    char ret;

    sprintf(retp, "%x", val);
    ret = retp[0];
    
    free(retp);
    return ret;
}

char* toHex(int num) {
    char* ret = calloc(9, sizeof(char));
    int retSize = 0;
    unsigned int unum = num >= 0 ? num : (unsigned int)(-(num+1)) + 1;

    if (num == 0)
    {
        ret[0] = '0';
        return ret;
    }

    if (num < 0)
        unum = 0xFFFFFFFF - (unum - 1);

    for (; unum != 0; unum >>= 4)
        ret[retSize++] = singleToHex(unum & 0xF);

    for (int i = 0; i < retSize / 2; i++)
    {
        int a = ret[i];
        ret[i] = ret[retSize-1-i];
        ret[retSize-1-i] = a;
    }
    return ret;
}
