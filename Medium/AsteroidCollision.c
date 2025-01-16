/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize) {
    int* ret = malloc(asteroidsSize * sizeof(int));
    int aidx = 0;
    *returnSize = 0;

    for (; aidx < asteroidsSize; aidx++)
    {
        if (asteroids[aidx] > 0)
        for (int i = 1; 
             aidx + i <= asteroidsSize - 1 ? asteroids[aidx+i] <= 0 : false; 
             i++)
        {
            if (asteroids[aidx+i] == 0)
                continue;

            if (asteroids[aidx] + asteroids[aidx+i] > 0)
            {
                asteroids[aidx+i] = 0;
            }
            else if (asteroids[aidx] + asteroids[aidx+i] < 0)
            {
                asteroids[aidx] = 0;
                aidx += i;
                break;
            }
            else
            {
                asteroids[aidx] = 0;
                asteroids[aidx+i] = 0;
                break;
            }
        }

        if (asteroids[aidx] < 0)
        for (int i = 1; 
             aidx - i >= 0 ? asteroids[aidx-i] >= 0 : false; 
             i++)
        {
            if (asteroids[aidx-i] == 0)
                continue;

            if (asteroids[aidx] + asteroids[aidx-i] < 0)
            {
                asteroids[aidx-i] = 0;
            }
            else if (asteroids[aidx] + asteroids[aidx-i] > 0)
            {
                asteroids[aidx] = 0;
                aidx -= i;
                break;
            }
            else
            {
                asteroids[aidx] = 0;
                asteroids[aidx-i] = 0;
                break;
            }
        }
    }

    for (int i = 0; i < asteroidsSize; i++)
        if (asteroids[i] != 0) 
            ret[(*returnSize)++] = asteroids[i];
    
    return ret;
}
