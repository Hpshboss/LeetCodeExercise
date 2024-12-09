char * mergeAlternately(char * word1, char * word2){
    char* ret = malloc((strlen(word1) + strlen(word2) + 10) * sizeof(char));
    char* retsp = ret;

    for (;(*word1 != '\0') && (*word2 != '\0'); word1++, word2++, ret+= 2)
    {
        sprintf(ret, "%c%c", *word1, *word2);
    }

    if (*word1 == '\0')
        sprintf(ret, "%s", word2);
    else
        sprintf(ret, "%s", word1);
    
    ret = retsp;

    return ret;
}
