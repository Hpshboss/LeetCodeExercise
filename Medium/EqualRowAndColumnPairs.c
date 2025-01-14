int compare(const void* a, const void* b) {
    unsigned long long int A = *(unsigned long long int*)a;
    unsigned long long int B = *(unsigned long long int*)b;
    if (A < B) return -1;
    if (A > B) return  1;
    return 0;
}

int equalPairs(int** grid, int gridSize, int* gridColSize) {
    unsigned long long int* rmaps = malloc(gridSize * sizeof(unsigned long long int));
    unsigned long long int* cmaps = malloc((*gridColSize) * sizeof(unsigned long long int));
    int tmp = 0;
    int rcnt = 1;
    int ccnt = 1;
    int ret = 0;

    for (int i = 0; i < gridSize; i++)
        for (int j = 0; j < *gridColSize; j++)
            if (gridSize > 4)
                cmaps[i] += (unsigned long long int)grid[i][j] << (j % 64);
            else
                cmaps[i] += (unsigned long long int)grid[i][j] << (j * 16);

    for (int j = 0; j < *gridColSize; j++)
        for (int i = 0; i < gridSize; i++)
            if (gridSize > 4)
                rmaps[j] += (unsigned long long int)grid[i][j] << (i % 64);
            else
                rmaps[j] += (unsigned long long int)grid[i][j] << (i * 16);
    
    qsort(rmaps, gridSize, sizeof(unsigned long long int), compare);
    qsort(cmaps, (*gridColSize), sizeof(unsigned long long int), compare);

    // for (int i = 0; i < gridSize; i++)
    //     printf("%llu, ", rmaps[i]);
    // printf("\n");
    // for (int i = 0; i < gridSize; i++)
    //     printf("%llu, ", cmaps[i]);
    // printf("\n");

    for (int i = 0, j = 0; i < gridSize && j < gridSize;)
    {
        // printf("i=%d, j=%d\n", i, j);
        if (rmaps[i] > cmaps[j])
        {
            j++;
            continue;
        }
        if (rmaps[i] < cmaps[j])
        {
            i++;
            continue;
        }

        if (i < gridSize - 1)
        for (i++; rmaps[i] == rmaps[i-1]; i++)
        {
            rcnt++;
            if (i == gridSize - 1)
            {
                i++;
                break;
            }
        }
        else i++;

        if (j < gridSize - 1)
        for (j++; cmaps[j] == cmaps[j-1]; j++)
        {
            ccnt++;
            if (j == gridSize - 1)
            {
                j++;
                break;
            }
        }
        else j++;

        // printf("i=%d, j=%d, added ret=%d\n", i, j, rcnt * ccnt);
        ret += (rcnt * ccnt);
        rcnt = 1; ccnt = 1;
    }

    return ret;
}
