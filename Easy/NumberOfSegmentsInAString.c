int countSegments(char* s) {
    int spacnt = 0;
    int len = strlen(s);

    int sidx = 0;
    int eidx = len - 1;

    if (len == 0)
        return 0;

    for (; s[sidx] == ' '; sidx++)
        if (sidx == len - 1)
            return 0;
    
    for (; s[eidx] == ' '; eidx--)
        if (eidx == 0)
            return 0;
    
    for (int i = sidx; i < eidx; i++)
        if (s[i] == ' ' && s[i+1] != ' ')
            spacnt++;

    return spacnt + 1;
}
