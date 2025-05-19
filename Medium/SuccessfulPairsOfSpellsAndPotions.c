/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int ascending(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int getFirstIdxPotionsHitSuccess(int spellval, int* potions, int potionsSize, int lidx, int ridx, long long success) {
    int mid = (lidx + ridx) / 2;
    long long val = 0;
    int ret = 0;
    if ((long long) spellval * potions[lidx] >= success)
        return ret;
    
    while (lidx < mid)
    {
        val = (long long) spellval * potions[mid];
        
        if (val >= success)
            ridx = mid;
        else
            lidx = mid;

        mid = (lidx + ridx)  / 2;
    }

    return (long long)potions[mid + 1] * spellval >= success ? mid + 1 : mid + 2;
}

int* successfulPairs(int* spells, int spellsSize, int* potions, int potionsSize, long long success, int* returnSize) {
    int psidx = 0; // potions starting index
    int* ret = malloc(spellsSize * sizeof(int));

    *returnSize = spellsSize;
    qsort(potions, potionsSize, sizeof(int), ascending);

    for (int i = 0; i < spellsSize; i++)
    {
        psidx = getFirstIdxPotionsHitSuccess(spells[i], potions, potionsSize, 0, potionsSize - 1, success);
        ret[i] = potionsSize - psidx;
    }

    return ret;
}

