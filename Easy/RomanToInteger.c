int checkRomanChar(char s) {
    switch(s) {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return -1; 
    }
}

int romanToInt(char* s) {
    int ret = 0;

    int left = 0;
    int right = 0;
    while (1) 
    {
        if(*s == NULL) break;
        left = checkRomanChar(*(s));
        if (*(s+1) != NULL) right = checkRomanChar(*(s+1));
        if(left < right) 
        {
            ret -= left;
        } 
        else 
        {
            ret += left;
        }
        s++;
    }
    return ret;
}
