/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* missingRolls(int* rolls, int rollsSize, int mean, int n, int* returnSize) {
    int* nRolls = malloc(n * sizeof(int));
    int allSum = mean * (rollsSize + n);
    int nSum = allSum;

    for (int i = 0; i < rollsSize; i++) nSum -= rolls[i];
    
    int nAvgInt = nSum / n;
    int nRemainder = nSum % n;
    
    if ((nAvgInt <= 0) ||
        (nAvgInt > 6) ||
        (nAvgInt == 6 && nRemainder > 0)) 
    {
        *returnSize = 0;
        return NULL;
    }

    for (int i = 0; i < n; i++) nRolls[i] = nAvgInt;
    for (int i = 0; i < nRemainder; i++) nRolls[i] = nRolls[i] + 1;

    *returnSize = n;
    return nRolls;
}
