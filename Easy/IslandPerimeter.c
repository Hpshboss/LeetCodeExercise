int islandPerimeter(int** grid, int gridSize, int* gridColSize) {
    int ret = 0;
    int prev = 0;
    int seperatecnt = 0;

    for (int i = 0; i < gridSize; i++, prev = 0)
    {
        for (int j = 0; j < *gridColSize; j++)
        {
            if (grid[i][j] == 1)
            {
                if (prev == 0)
                    seperatecnt++;
                prev = 1;
            }
            else prev = 0;
        }
    }

    for (int i = 0; i < *gridColSize; i++, prev = 0)
    {
        for (int j = 0; j < gridSize; j++)
        {
            if (grid[j][i] == 1)
            {
                if (prev == 0)
                    seperatecnt++;
                prev = 1;
            }
            else prev = 0;
        }
    }

    ret += seperatecnt * 2;

    return ret;
}
