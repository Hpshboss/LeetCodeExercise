char* removeStars(char* s) {
    char* ret = malloc((strlen(s)+1) * sizeof(char));
    int idx = 0;

    for (; *s != 0; s++)
    {
        if (*s == '*')
            idx--;
        else
            ret[idx++] = *s;
    }

    ret[idx] = 0;
    return ret;
}
