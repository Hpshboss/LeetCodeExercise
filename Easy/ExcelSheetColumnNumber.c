int titleToNumber(char* columnTitle) {
    int ret = 0;
    int digiVal = 1;
    int len = strlen(columnTitle);

    ret += (((int)columnTitle[len-1]) - 64);
    for (int i = 1; i < len; i++)
    {
        digiVal *= 26;
        ret += (((int)columnTitle[len-i-1]) - 64) * digiVal;
    }
    
    return ret;
}
