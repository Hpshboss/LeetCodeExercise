void reverseString(char* s, int sSize) {
    char tmp;
    int halflen = sSize / 2;
    for (int i = 0; i < halflen; i++)
    {
        tmp = s[i];
        s[i] = s[sSize-i-1];
        s[sSize-i-1] = tmp;
    }
    return;
}
