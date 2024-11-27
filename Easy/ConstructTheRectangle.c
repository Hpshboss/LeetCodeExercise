/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* constructRectangle(int area, int* returnSize) {
    int W = 1, L = area > 4 ? area / 2 : area;
    int* ret = malloc(2 * sizeof(int));

    *returnSize = 2;

    while (W < L)
    {
        if (area % L == 0)
            W = area / L;
        L--;
    }

    ret[0] = area / W;
    ret[1] = W;

    return ret;
}
