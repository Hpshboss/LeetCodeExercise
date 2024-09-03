bool isIsomorphic(char* s, char* t) {
    char* tTable = calloc(127, sizeof(char));
    char* sTable = calloc(127, sizeof(char));
    while (*s != '\0')
    {
        if (sTable[*s] == NULL && tTable[*t] == NULL)
        {
            sTable[*s] = *t;
            tTable[*t] = *s;
            s++; t++;
            continue;
        }
        
        if (sTable[*s] != *t) return false;
        if (tTable[*t] != *s) return false;

        s++; t++;
    }
    return true;
}
