char findTheDifference(char* s, char* t) {
    char* scnt = calloc(26, sizeof(char));
    char* tcnt = calloc(26, sizeof(char));

    while (*s != '\0')
    {
        scnt[*s-97] += 1;
        tcnt[*t-97] += 1;
        s++;
        t++;
    }
    tcnt[*t-97] += 1;
    
    for (int i = 0; i < 26; i++)
    {
        if (tcnt[i] > scnt[i])
        {
            free(scnt);
            free(tcnt);
            return (char) (97+i);
        }
    }

    free(scnt);
    free(tcnt);
    return 'a';
}
