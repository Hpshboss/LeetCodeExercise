int calcnt(int fidx, int fone, int bidx, int bone) {
    int tmp = bidx - fidx - fone - bone + 1;
    if (tmp & 1)
        return (tmp >> 1) + 1;
    else
        return tmp >> 1;
}

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    int fidx = -1;
    int fone = 0; // whether there is a one in front of fidx
    int bidx = -1;
    int bone = 0; // whether there is a one in back of bidx
    
    fidx = 0, fone = 0;
    for (int i = 0; i < flowerbedSize; i++)
    {
        if (flowerbed[i] == 1)
        {
            bidx = i - 1, bone = 1;

            if (bidx > fidx)
                n -= calcnt(fidx, fone, bidx, bone);

            fidx = i + 1, fone = 1;
        }
        else
        {
            if (i == flowerbedSize - 1)
            {
                bidx = i, bone = 0;

                if (bidx >= fidx)
                    n -= calcnt(fidx, fone, bidx, bone);
            }
        }
    }

    return n <= 0 ? true : false;
}
