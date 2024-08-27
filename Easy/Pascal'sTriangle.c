/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    int** ret = malloc(sizeof(int*) * numRows);
    *returnSize = numRows;
    *returnColumnSizes = malloc(sizeof(int*) * numRows);

    for (int i = 0; i < numRows; i++)
    {
        ret[i] = malloc(sizeof(int) * (i+1));
        (*returnColumnSizes)[i] = i + 1;
    }

    int* a = malloc(sizeof(int) * numRows);
    int* b = malloc(sizeof(int) * numRows);

    a[0] = 1; ret[0][0] = a[0];
    if (numRows == 1) return ret;
    b[0] = 1; b[1] = 1;
    for (int i = 2; i <= numRows; i++)
    {
        if (i % 2 == 0) 
        { 
            b[0] = 1; b[i-1] = 1; 
            ret[i-1][0] = b[0]; ret[i-1][i-1] = b[i-1]; 
        }
        else 
        { 
            a[0] = 1; a[i-1] = 1; 
            ret[i-1][0] = a[0]; ret[i-1][i-1] = a[i-1]; 
        }
        for (int j = 1; j < i - 1; j++)
        {
            if (i % 2 == 0) 
            { 
                b[j] = a[j-1] + a[j]; 
                ret[i-1][j] = b[j]; 
            }
            else 
            { 
                a[j] = b[j-1] + b[j]; 
                ret[i-1][j] = a[j]; 
            }
        }
    }
    return ret;
}
