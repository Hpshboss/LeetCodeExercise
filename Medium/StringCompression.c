int compress(char* chars, int charsSize) {
    int ret = 1;
    int gcnt = 1;
    int idx = 0;
    int tmp = 0;
    int digits = 0;

    for (int i = 0; i < charsSize; i++)
    {
        if (i < charsSize - 1)
        if (chars[i] == chars[i+1])
        {
            gcnt++;
            continue;
        }
        
        if (gcnt == 1)
        {
            chars[idx++] = chars[i];
        }
        else
        {
            chars[idx++] = chars[i];
            
            /*check digitals*/
            tmp = gcnt;
            digits = 0;
            for (;tmp > 0; tmp /= 10)
                digits++;
            /*put number by digit*/
            for (int i = 0; i < digits; i++)
            {
                chars[idx++] = (gcnt / (int)pow(10, digits - i - 1)) + 48;
                gcnt %= (int)pow(10, digits - i - 1);
            }
        }
        gcnt = 1;
    }
    ret = idx;
    return ret;
}
