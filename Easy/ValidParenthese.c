int checkChar(char* ss)
{
    switch(*ss)
    {
        case '(':
            return 1;
        case ')':
            return -1;
        case '[':
            return 2;
        case ']':
            return -2;
        case '{':
            return 3;
        case '}':
            return -3;
    }
    return 0;
}

bool isValid(char* s) 
{
    int* sstack = malloc(10001 * sizeof(int));
    *sstack = 999;
    sstack++;
    while(1)
    { 
        if (*s == 0)
        {
            if (*(sstack - 1) == 999) return true;
            return false;
        }
        
        *sstack = checkChar(s);
        if (*sstack > 0) 
        {
            sstack++;
        }
        else
        {
            if (*sstack + *(sstack - 1) == 0)
            {
                sstack--;
            } 
            else
            {
                return false;
            }
        }
        s++;
    }
}
