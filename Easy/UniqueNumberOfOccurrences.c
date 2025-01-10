int compare(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

bool uniqueOccurrences(int* arr, int arrSize) {
    int ret = true;
    int* map = calloc(2001, sizeof(int));

    for (int i = 0; i < arrSize; i++)
        map[arr[i]+1000]++;
    
    qsort(map, 2001, sizeof(int), compare);

    for (int i = 1; map[i] > 0; i++)
        if (map[i] == map[i-1])
            ret = false;
    
    free(map);
    return ret;
}
