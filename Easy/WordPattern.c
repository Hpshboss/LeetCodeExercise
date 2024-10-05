bool checkDuplicate(char** set, char*s) {
    int cnt = 0;
    for (int i = 0; i < 26; i++)
    {
        if (set[i] == NULL) continue;
        if (strcmp(set[i], s) == 0) cnt++;
    }
    return cnt > 1 ? true : false;
}

bool wordPattern(char* pattern, char* s) {
    char** words = malloc(1500 * sizeof(char*));
    int wordsSize = 0;
    char** set = malloc(26 * sizeof(char*));
    int idx = 0;

    char* token = strtok(s, " ");

    for (int i = 0; i < 26; i++) {
        set[i] = NULL;  // Initialize the set array to NULL
    }

    while (token != NULL)
    {
        words[wordsSize] = calloc(30, sizeof(char));
        strcat(words[wordsSize], token);
        wordsSize++;

        token = strtok(NULL, " ");
    }

    if (wordsSize != strlen(pattern)) return false;

    for (int i = 0; i < wordsSize; i++)
    {
        idx = pattern[i] - 97;
        if (set[idx] == NULL)
        {
            set[idx] = calloc(30, sizeof(int));
            strcat(set[idx], words[i]);
            if (checkDuplicate(set, set[idx])) return false;
        }
        else if (strcmp(set[idx], words[i]) != 0) return false;
    }
    return true;
}
