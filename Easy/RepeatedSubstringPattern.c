bool repeatedSubstringPattern(char* s) {
    int slen = strlen(s);
    int subslen = 0;

    for (subslen = 1; subslen <= slen / 2; subslen++)
    {
        if (slen % subslen > 0)
            continue;

        for (int i = subslen; i < slen; i++)
        {
            if (s[i] != s[i%subslen])
                break;
            if (i == slen - 1)
                return true;
        }
    }

    return false;
}
