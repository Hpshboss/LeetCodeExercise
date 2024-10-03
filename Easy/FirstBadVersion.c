// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
    int low = 1;
    int upper = n;
    int middle = ((upper - low) / 2) + low;

    if (isBadVersion(1) == true) return 1;

    while (middle != low)
    {
        if (isBadVersion(middle) == false)
        {
            low = middle;
        }
        else
        {
            upper = middle;
        }
        middle = ((upper - low) / 2) + low;
    }

    return upper;
}


