bool freeReturn(int* a, int* b, bool ret) {
    free(a);
    free(b);
    return ret;
}

bool canConstruct(char* ransomNote, char* magazine) {
    int rlen = strlen(ransomNote);
    int mlen = strlen(magazine);

    int* rcnts = calloc(26, sizeof(int));
    int* mcnts = calloc(26, sizeof(int));
    
    if (rlen > mlen) 
        return freeReturn(rcnts, mcnts, false);

    for (; *ransomNote != '\0'; ransomNote++)
        rcnts[*ransomNote-97] += 1;

    for (; *magazine != '\0'; magazine++)
        mcnts[*magazine-97] += 1;

    for (int i = 0; i < 26; i++)
    {
        if (rcnts[i] > mcnts[i])
            return freeReturn(rcnts, mcnts, false);
    }

    return freeReturn(rcnts, mcnts, true);
}
