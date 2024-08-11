int strStr(char* haystack, char* needle) {
    for (int i = 0; i <= 10000; i++)
    {
        if (haystack[i] == NULL) return -1;
        for (int j = 0; j <= 10000; j++)
        {
            printf("%d:%d\n", i, j);
            if (needle[j] == NULL) return i;
            if (haystack[i+j] != needle[j])
            {
                break;
            }
        }
    }
    return -1;
}
