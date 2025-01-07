int isVowel(char c) {
    switch (c)
    {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return 1;
        default:
            return 0;
    }
    return 0;
}

int maxVowels(char* s, int k) {
    int ret = 0;
    int lidx = 0;
    int ridx = k - 1;
    int cnt = 0;

    for (int i = 0; i < k; i++)
        cnt += isVowel(s[i]);

    ret = cnt > ret ? cnt : ret;

    for (lidx++, ridx++; s[ridx] != 0; lidx++, ridx++)
    {
        cnt -= isVowel(s[lidx-1]);
        cnt += isVowel(s[ridx]);

        ret = cnt > ret ? cnt : ret;
    }

    return ret;
}
