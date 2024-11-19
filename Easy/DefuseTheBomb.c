/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* decrypt(int* code, int codeSize, int k, int* returnSize) {
    int* rcode = calloc(codeSize, sizeof(int));

    *returnSize = codeSize;

    if (k > 0)
        for (int i = 0; i < codeSize; i++)
            for (int j = i + 1; j <= i + k; j++)
                rcode[i] += code[j % codeSize];
    
    else if (k < 0)
        for (int i = 0; i < codeSize; i++)
            for (int j = i - 1; j >= i + k; j--)
                rcode[i] += code[j < 0 ? codeSize + j : j];

    return rcode;
}
