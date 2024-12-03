char* convertToBase7(int num) {
    char* tmpret = malloc(12 * sizeof(char));
    char* ret = malloc(12 * sizeof(char));
    char* tmpretsp = tmpret;
    char* retsp = ret;
    int absnum = num > 0 ? num : -num;

    do
    {
        *tmpret = 48 + absnum % 7;
        absnum /= 7;
        tmpret++;
    }
    while (absnum > 0);

    *tmpret = '\0';
    tmpret = tmpretsp;

    if (num < 0)
        *ret = 45, ret++;

    for (int i = 0; i < strlen(tmpretsp); i++)
    {
        *ret = tmpret[strlen(tmpretsp)-i-1];
        ret++;
    }
    *ret = '\0';
    ret = retsp;

    free(tmpret);

    return ret;
}
