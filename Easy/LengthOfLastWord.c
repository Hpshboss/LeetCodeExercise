int lengthOfLastWord(char* s) {
    int cnt = 0;
    int ret = 0;
    while (*s != '\0')
    {
        if (*s == ' ')
        {
            cnt = 0;
        }
        else
        {
            cnt++;
            ret = cnt;
        }
        s++;
    }
    return ret;
}
