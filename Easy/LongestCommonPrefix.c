char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) return "";

    char * cstrs = malloc(201 * sizeof(char));
    char cstr = "";
    for (int i = 0; i < 201; i++)
    {
        cstr = *(*strs + i);
        if (cstr == 0)
        {
            cstrs[i] = '\0';
            return cstrs;
        } 
        for (int j = 0; j < strsSize; j++)
        {
            if (cstr != *(*(strs + j) + i))
            {
                cstrs[i] = '\0'; // 结束字符串 (GPT Modified)
                return cstrs;
            }
        }
        *(cstrs + i) = *(*strs + i);
    }
    cstrs[200] = '\0'; // 确保字符串以'\0'结束 (GPT Modified)
    return cstrs;
}
