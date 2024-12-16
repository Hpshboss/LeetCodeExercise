/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {
    int max = 0;
    bool* ret = malloc(candiesSize * sizeof(bool));

    *returnSize = candiesSize;

    for (int i = 0; i < candiesSize; i++)
        max = candies[i] > max ? candies[i] : max;
    
    for (int i = 0; i < candiesSize; i++)
        if (candies[i] + extraCandies >= max)
            ret[i] = true;
        else
            ret[i] = false;
    
    return ret;
}
