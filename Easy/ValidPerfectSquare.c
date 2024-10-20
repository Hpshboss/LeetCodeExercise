#define SQUARE(x) (x*x)

bool isPerfectSquare(int num) {
    int left = 0;
    int right = num > 10000 ? num / 100 : num;
    int mid = (left + right) / 2;
    int square = 0;

    if (right > 46340) // prevent overflow of integer 
    {
        right = 46340;
        mid = (left + right) / 2;
    }

    while (right - left > 1)
    {
        square = SQUARE(mid);
        if (square == num) return true;

        if (square > num) right = mid;
        if (square < num) left = mid;

        mid = (left + right) / 2;
    }

    if (SQUARE(right) == num) return true;
    return false;
}
