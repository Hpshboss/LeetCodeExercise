bool isAnagram(char* s, char* t) {
    int* schars = calloc(26, sizeof(int));
    int* tchars = calloc(26, sizeof(int));

    for (; *s != '\0'; s++) schars[(*s)-97] += 1;
    for (; *t != '\0'; t++) tchars[(*t)-97] += 1;

    for (int i = 0; i < 26; i++)
    {
        if (schars[i] != tchars[i])
        {
            free(schars);
            free(tchars);
            return false;
        }
    }
    
    free(schars);
    free(tchars);
    return true;
}
