#define MINH(L, R) L < R ? L : R

int maxArea(int* height, int heightSize) {
    int width = heightSize - 1;
    int rmaxh = 0; // relative max height for all
    int rminh = 0; // two line height compare
    int amaxh = 0; // absolute height
    int rmaxa = 0; // relative max area
    int amaxa = 0; // absolute max area
    
    for (; width > 0; width--)
    {
        for (int i = 0; i < heightSize - width; i++)
        {
            rminh = MINH(height[i], height[i+width]);
            rmaxh = rminh > rmaxh ? rminh : rmaxh;
        }
        if (rmaxh > amaxh)
        {
            rmaxa = rmaxh * width;
            amaxa = amaxa > rmaxa ? amaxa : rmaxa;
        }
    }

    return amaxa;
}
