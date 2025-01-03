#define MINH(L, R) L < R ? L : R

int maxArea(int* height, int heightSize) {
    int ret = 0;
    int area = 0;
    int lidx = 0;
    int ridx = heightSize - 1;

    while (ridx > lidx)
    {
        area = (ridx - lidx) * (MINH(height[lidx], height[ridx]));
        ret = area > ret ? area : ret;

        if (height[lidx] > height[ridx])
            ridx--;
        else
            lidx++;
    }

    return ret;
}
