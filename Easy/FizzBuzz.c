/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fizzBuzz(int n, int* returnSize) {
    char** ret = malloc(n * sizeof(char*));
    *returnSize = n;

    for (int i = 0; i < n; i++)
    {
        ret[i] = calloc(9, sizeof(char));
        bool is3mult = (i+1) % 3 == 0;
        bool is5mult = (i+1) % 5 == 0;

        if (is3mult && is5mult)
            sprintf(ret[i], "FizzBuzz");
        else if (is3mult)
            sprintf(ret[i], "Fizz");
        else if (is5mult)
            sprintf(ret[i], "Buzz");
        else
            sprintf(ret[i], "%d", i+1);
    }
    
    return ret;
}
