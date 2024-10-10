/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int n, int* returnSize) {
    int* ret = calloc(n+1, sizeof(int));
    int base = 2;

    *returnSize = n + 1;

    if (n == 0) return ret;

    ret[1] = 1;
    if (n == 1) return ret;

    ret[2] = 1;
    for (int i = 3; i < *returnSize; i++)
    {
        if (i == base << 1)
        {
            base = base << 1;
            ret[i] = 1;
        }
        else
        {
            ret[i] = ret[i - base] + 1;
        }
    }
    return ret;
}
