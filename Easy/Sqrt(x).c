#define CheckPowRange(num, target) (num*num <= target) & ((num+1)*(num+1) > target)

int mySqrt(int x) {
    if (x == 1) return 1;
    int lnum = 0;
    int rnum = x;
    long midnum = (lnum + rnum) / 2;

    while (1)
    {
        if (CheckPowRange(midnum, x))
        {
            return midnum;
        }
        else if (midnum * midnum > x)
        {
            rnum = midnum;
        }
        else
        {
            lnum = midnum;
        }
        midnum = (lnum + rnum) / 2;
    }
    return -1;
}
