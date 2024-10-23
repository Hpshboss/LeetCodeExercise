int firstUniqChar(char* s) {
    int* cnts = calloc(26, sizeof(int));
    int* idxs = calloc(26, sizeof(int));

    int len = strlen(s);
    int ret = len;

    for (int i = 0; i < len; i++)
    {
        if (cnts[s[i]-97] == 0) idxs[s[i]-97] = i;
        cnts[s[i]-97]++;
    }

    for (int i = 0; i < 26; i++)
    {
        if (cnts[i] == 1)
        {
            ret = ret < idxs[i] ? ret : idxs[i];
        }
    }

    free(cnts);
    free(idxs);

    if (ret == len) return ret = -1;

    return ret;
}
