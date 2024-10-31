int longestPalindrome(char* s) {
    int len = strlen(s);
    int ret = len;
    int lidx = 0, ridx = ret - 1;
    
    while (ret > 1)
    {
        for (int i = 0; i <= len - ret; i++)
        {
            for (lidx=i, ridx=ret+i-1;
                 s[lidx] == s[ridx]; 
                 lidx++, ridx--)
            {
                if (ridx - lidx <= 1)
                    return ret;
            }
        }

        ret--;
    }
    return ret;
}
