int* findAllFactors(int num, int* returnSize) {
    int* ret = malloc(1000 * sizeof(int));
    int ulimit = num % 2 == 0 ? num / 2 : num / 3;

    *returnSize = 0;

    for (int i = 1; i <= ulimit; i++)
        if (num % i == 0)
            ret[(*returnSize)++] = i, printf("%d\n", i);
        
    return ret;
}

bool checkPerfectNumber(int num) {
    int* fctsSize = malloc(sizeof(int));
    int* fcts = findAllFactors(num, fctsSize);

    for (int i = 0; i < *fctsSize; i++)
        num -= fcts[i];

    free(fctsSize);
    free(fcts);
    if (num == 0)
        return true;

    return false;
}
