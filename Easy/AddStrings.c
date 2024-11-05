char* addStrings(char* num1, char* num2) {
    int num1len = strlen(num1);
    int num2len = strlen(num2);

    int retlen = num1len > num2len ? num1len + 1 : num2len + 1;
    char* ret = calloc(retlen + 1, sizeof(char));

    for (int i = 0; i < retlen - 1; i++)
    {
        if (num1len-i-1 >= 0 && num2len-i-1 >= 0)
            ret[retlen-i-1] = num1[num1len-i-1] + num2[num2len-i-1] - 48;
        else if (num1len-i-1 >= 0)
            ret[retlen-i-1] = num1[num1len-i-1];
        else if (num2len-i-1 >= 0)
            ret[retlen-i-1] = num2[num2len-i-1];
    }

    for (int i = 0; i < retlen - 1; i++)
    {
        if (ret[retlen-i-1] - 48 >= 10)
        {
            ret[retlen-i-2] += 1;
            ret[retlen-i-1] -= 10;
        }
    }
    *ret += 48;
    if (*ret == 48)
        ret++;
    return ret;
}
