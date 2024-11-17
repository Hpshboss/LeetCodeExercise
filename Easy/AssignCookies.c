int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int findContentChildren(int* g, int gSize, int* s, int sSize) {
    int ret = 0;
    int* isShared = calloc(gSize, sizeof(int));

    qsort(g, gSize, sizeof(int), compare);

    for (int i = 0; i < sSize; i++)
    {
        int lidx = 0;
        int ridx = gSize;
        int midx = (lidx + ridx) >> 1;

        while (midx > 0 & ridx != (lidx + 1))
        {
            int delta = s[i] - g[midx];

            if (delta >= 0)
                lidx = midx;
            else
                ridx = midx;

            midx = (lidx + ridx) >> 1;
        }

        if (midx == 0)
            lidx = midx;

        for (int j = lidx; j >= 0; j--)
        {
            if (s[i] - g[j] < 0)
                break;
            
            if (isShared[j] == 0)
            {
                isShared[j] = 1;
                break;
            }
        }
    }
    for (int j = 0; j < gSize; j++)
    {
        ret += isShared[j];
    }
    
    free(isShared);
    return ret;
}
