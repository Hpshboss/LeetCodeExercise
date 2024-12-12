int* findAllFactors(int num, int* returnSize) {
    int* ret = malloc(1000 * sizeof(int));
    int ulimit = num % 2 == 0 ? num / 2 : num / 3;

    *returnSize = 0;

    for (int i = 1; i <= ulimit; i++)
        if (num % i == 0)
            ret[(*returnSize)++] = i;
        
    ret[(*returnSize)++] = num;

    return ret;
}

char* gcdOfStrings(char* str1, char* str2) {
    int str1len = strlen(str1);
    int str2len = strlen(str2);
    int blen = str1len > str2len ? str1len : str2len;
    int slen = str1len < str2len ? str1len : str2len;
    char* ret = malloc((slen+1) * sizeof(char));
    int* fctsSize = malloc(sizeof(int));
    int* fcts = findAllFactors(slen, fctsSize);

    int midx = 0;
    int idx = 0;

    for (int i = 0; i < *fctsSize; i++)
    {
        if (blen % fcts[*fctsSize - i -1] == 0)
        {
            midx = fcts[*fctsSize - i -1];
            break;
        }
    }

    // printf("midx=%d\n", midx);
    
    for (int i = 0; i < blen; i++)
    {
        if (i >= str1len)
        {
            if (str2[i] != str2[i % midx])
            {
                free(fcts);
                free(fctsSize);
                *ret = '\0';
                return ret;
            }
            continue;
        }
        if (i >= str2len)
        {
            if (str1[i] != str1[i % midx])
            {
                free(fcts);
                free(fctsSize);
                *ret = '\0';
                return ret;
            }
            continue;
        }
        if ((str1[i] != str1[i % midx]) || (str2[i] != str1[i % midx]))
        {
            free(fcts);
            free(fctsSize);
            *ret = '\0';
            return ret;
        }
    }

    for (int i = 0; i < midx; i++)
        ret[i] = str1[i];
    ret[midx] = '\0';
    
    free(fcts);
    free(fctsSize);

    return ret;
}
