/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findWords(char** words, int wordsSize, int* returnSize) {
    int* pos = malloc(26 * sizeof(int));
    int tmp = 0;

    char *rows[] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
    char ** ret = malloc(wordsSize * sizeof(char*));

    *returnSize = 0;

    for (int i = 0; i < wordsSize; i++)
        ret[i] = malloc(21 * sizeof(char));

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < strlen(rows[i]); j++)
            pos[rows[i][j]-97] = 1 << i;

    for (int i = 0; i < wordsSize; i++)
    {   
        tmp = 0;

        for (int j = 0; j < strlen(words[i]); j++)
            tmp |= pos[(words[i][j] < 91 ? words[i][j] + 32 : words[i][j])-97];
        
        if (tmp == 1 || tmp == 2 || tmp == 4)
            ret[(*returnSize)++] = words[i];
    }

    return ret;
}
