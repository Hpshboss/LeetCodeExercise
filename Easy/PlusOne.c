/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int *ret = malloc((digitsSize + 1) * sizeof(int));

    digits[digitsSize - 1] += 1;
    for (int i = digitsSize - 1; i > 0; i--)
    {
        if (digits[i] == 10)
        {
            digits[i] = 0;
            digits[i-1] += 1;
        }
        ret[i+1] = digits[i];
    }

    if (digits[0] == 10)
    {
        ret[1] = 0; ret[0] = 1;
        *returnSize = digitsSize + 1;
    }
    else
    {
        ret[1] = digits[0];
        ret++;
        *returnSize = digitsSize;
    }

    return ret;
}
