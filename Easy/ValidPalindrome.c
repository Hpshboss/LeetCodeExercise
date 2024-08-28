#define CHECKRANGE(x, r1, r2) x > r1 && x < r2

bool isPalindrome(char* s) {
    int len = strlen(s);
    int i = 0, j = len - 1;
    while (i < j)
    {
        if (s[i] > 96) s[i] -= 32;
        if (s[j] > 96) s[j] -= 32;

        if (!(CHECKRANGE(s[i], 47, 58) || CHECKRANGE(s[i], 64, 91))) { i++; continue; }
        if (!(CHECKRANGE(s[j], 47, 58) || CHECKRANGE(s[j], 64, 91))) { j--; continue; }

        if (s[i] != s[j]) return false;
        i++; j--;
    }
    return true;
}
