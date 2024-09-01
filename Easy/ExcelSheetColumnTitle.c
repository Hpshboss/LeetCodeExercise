char* convertToTitle(int columnNumber) {
    char* tmp = malloc(8 * sizeof(char));
    char* sp = tmp;
    int len = 0;
    char *ret = malloc(8 * sizeof(char));
    int remainder = 0;

    while (columnNumber != 0)
    {
        columnNumber--;
        remainder = columnNumber % 26;
        *tmp = remainder + 'A'; tmp++;
        columnNumber = columnNumber / 26;
    }
    *tmp = '\0';

    len = strlen(sp);
    for (int i = 0; i < len; i++) ret[i] = sp[len-i-1];
    ret[len] = '\0';

    return ret;
}
