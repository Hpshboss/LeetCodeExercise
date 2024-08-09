int log_a_to_base_b(int a, int b)
{
    return (a > b - 1)
               ? 1 + log_a_to_base_b(a / b, b)
               : 0;
}

int powInt(int a, int b) {
    int ret = 1;
    for (int i = 0; i < b; i++) {
        ret *= a;
    }
    return ret;
}

bool isPalindrome(int x) {
    if (x < 0) { return false; }
    if (x < 10) { return true; }

    int numDigit = log_a_to_base_b(x, 10) + 1;

    int rightDigit = -1;
    int leftDigit = -2;
    for (int i = 1; i <= numDigit / 2; i++)
    {
        rightDigit = (x / powInt(10, i-1)) % 10;
        leftDigit = (x / powInt(10, numDigit - i)) % 10;
        if (rightDigit != leftDigit) { return false; }
        rightDigit = -1;
        leftDigit = -2;
    }
    return true;
}
