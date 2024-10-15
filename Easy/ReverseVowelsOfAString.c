bool checkVowel(char s)
{
    switch (s)
    {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            return true;
        default:
            return false;
    }
    return false;
}

char* reverseVowels(char* s) {
    char tmp;
    int i = 0;
    int j = strlen(s) - 1;

    while (i < j)
    {
        if (!checkVowel(s[i]))
        {
            i++;
            continue;
        }
        if (!checkVowel(s[j]))
        {
            j--;
            continue;
        }
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
        i++; j--;
    }
    return s;
}
