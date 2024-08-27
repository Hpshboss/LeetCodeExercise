/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize) {
    
    int* a = malloc((rowIndex+1) * sizeof(int));
    int* b = malloc((rowIndex+1) * sizeof(int));
    *returnSize = rowIndex+1;

    a[0] = 1; if (rowIndex == 0) return a;
    b[0] = 1; b[1] = 1;
    for (int i = 2; i < rowIndex + 1; i++)
    {
        if (i % 2 == 0) { a[0] = 1; a[i] = 1; }
        else { b[0] = 1; b[i] = 1; }
        
        for (int j = 0; j < i - 1; j++)
        {
            if (i % 2 == 0) { a[j+1] = b[j] + b[j+1]; }
            else { b[j+1] = a[j] + a[j+1]; }
        }
    }
    if (rowIndex % 2 == 0) { return a; }
    else { return b; }
}
