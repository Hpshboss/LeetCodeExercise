bool isTwo(int n) {
    if (n & 1) return false;
    return true;
}

bool isThree(int n) {
    int sum = 0;
    for (; n > 0; n = n / 10) sum += n % 10;
    if (sum % 3) return false;
    return true;
}

bool isFive(int n) {
    if (n % 10 == 5) return true;
    if (n % 10 == 0) return true;
    return false;
}

bool isUgly(int n) {
    if (n < 1) return false;
    while (1)
    {
        if (isTwo(n)) n /= 2;
        else if (isThree(n)) n /= 3;
        else if (isFive(n)) n /= 5;
        else
        {
            if (n == 1) return true;
            return false;
        }
    }
    return false;
}
