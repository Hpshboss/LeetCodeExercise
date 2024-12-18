char* reverseWords(char* s) {
    int slen = strlen(s);
    char* ret = malloc((slen+1) * sizeof(char));
    int ridx = 0;

    int widx = 0;
    int wlen = 0;

    for (int i = slen - 1; i >= 0; i--)
    {
        if (s[i] == ' ' && wlen > 0)
        {
            for (int j = 0; j < wlen; j++)
            {
                ret[ridx++] = s[i+j+1];
            }
            ret[ridx++] = ' ';
            wlen = 0;
            continue;
        }
        if (s[i] != ' ')
        {
            wlen++;
        }
        if (i == 0 && wlen > 0)
        {
            for (int j = 0; j < wlen; j++)
            {
                ret[ridx++] = s[i+j];
            }
            wlen = 0;
        }
    }

    if (ret[ridx-1] == ' ')
        ret[--ridx] = 0;
    else
        ret[ridx] = 0;
    
    return ret;
}
