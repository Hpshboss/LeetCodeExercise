bool isSubsequence(char* s, char* t) {
    for (;*s != '\0'; s++)
    {
        for (;*s != *t; t++)
            if (*t == '\0')
                return false;
        t++;
    }
    return true;
}
