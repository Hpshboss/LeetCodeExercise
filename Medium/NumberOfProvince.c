bool checkDirectCities(int* cpoint, // Checking Point (i, j)
                       int dir, // Check Direction in isConnected Matrix(0: Row; 1: Column)
                       int** isConnected, 
                       int isConnectedSize, 
                       int* isConnectedColSize)
{
    bool tmp = false;
    bool isAnyConnected = false;

    if (dir == 0)
    for (int j = 0, i = cpoint[0]; j < isConnectedSize; j++)
    {
        // printf("Row=> i: %d; j:%d\n", i, j);
        if (isConnected[i][j] == 1)
        {
            isConnected[i][j] = 0;

            if (i == j)
            {
                isAnyConnected = true;
                continue;
            }

            cpoint[1] = j;
            tmp = checkDirectCities(cpoint, 1, isConnected, isConnectedSize, isConnectedColSize);
            isAnyConnected = isAnyConnected || tmp;
        }
    }
    if (dir == 1)
    for (int i = 0, j = cpoint[1]; i < isConnectedSize; i++)
    {
        // printf("Col=> i: %d; j:%d\n", i, j);
        if (isConnected[i][j] == 1)
        {
            isConnected[i][j] = 0;

            if (i == j)
            {
                isAnyConnected = true;
                continue;
            }

            cpoint[0] = i;
            tmp = checkDirectCities(cpoint, 0, isConnected, isConnectedSize,  isConnectedColSize);
            isAnyConnected = isAnyConnected || tmp;
        }
    }

    return isAnyConnected;
}

int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize) 
{
    int cnt = 0;
    int cpoint[2] = {0, 0};

    for (int i = 0; i < isConnectedSize; i++)
    {
        cpoint[0] = i;
        if (checkDirectCities(cpoint, 0, isConnected, isConnectedSize, isConnectedColSize))
            cnt++;
    }

    return cnt;
}
