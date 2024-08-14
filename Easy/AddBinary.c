char* addBinary(char* a, char* b) {
    int alen = strlen(a);
    int blen = strlen(b);

    int maxlen = alen > blen ? alen : blen;

    char* ret = malloc((maxlen+2) * sizeof(char));

    int carry = 0;
    for (int i = -1; i >= -maxlen; i--)
    {
        if (alen + i < 0) 
        { 
            if (b[blen + i] == '1') 
            {
                ret[maxlen + i + 1] = carry == 1 ? '0' : '1';
            }
            else
            {
                ret[maxlen + i + 1] = carry == 1 ? '1' : '0';
                carry = 0;
            }

            continue; 
        }
        if (blen + i < 0) 
        { 
            if (a[alen + i] == '1') 
            {
                ret[maxlen + i + 1] = carry == 1 ? '0' : '1';
            }
            else
            {
                ret[maxlen + i + 1] = carry == 1 ? '1' : '0';
                carry = 0;
            }
            continue; 
        }
        
        if ((a[alen + i] == '1') & (b[blen + i] == '1'))
        {
            ret[maxlen + i + 1] = carry == 1 ? '1' : '0';
            carry = 1;
        }
        else if ((a[alen + i] == '1') | (b[blen + i] == '1'))
        {
            ret[maxlen + i + 1] = carry == 1 ? '0' : '1';
        }
        else
        {
            ret[maxlen + i + 1] = carry == 1 ? '1' : '0';
            carry = 0;
        }
    }
    if (carry == 1)
    {
        ret[0] = '1';
        ret[maxlen+1] = '\0';
    }
    else
    {
        ret++;
        ret[maxlen] = '\0';
    }
    return ret;
}
