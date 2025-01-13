#define ALPHABET_CNT 26

bool closeStrings(char* word1, char* word2) {
    int ret = true;
    int wlen1 = strlen(word1);
    int wlen2 = strlen(word2);
    int* map1 = calloc(ALPHABET_CNT, sizeof(int));
    int* map2 = calloc(ALPHABET_CNT, sizeof(int));

    if (wlen1 != wlen2)
    {
        free(map1);
        free(map2);
        return false;
    }

    for (; *word1 != 0; word1++)
        map1[*word1-97]++;
    
    for (; *word2 != 0; word2++)
        map2[*word2-97]++;
    
    for (int i = 0; i < ALPHABET_CNT; i++)
        if (map1[i] > 0 ^ map2[i] > 0)
            ret = false;

    for (int i = 0; i < ALPHABET_CNT; i++)
        for (int j = 0; j < ALPHABET_CNT; j++)
            if (map1[i] == map2[j])
                map1[i] = 0, map2[j] = 0;

    for (int i = 0; i < ALPHABET_CNT; i++)
        if (map1[i] != 0 || map2[i] != 0)
            ret = false;
    
    free(map1);
    free(map2);
    return ret;
}
