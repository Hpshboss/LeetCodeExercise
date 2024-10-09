#define LEFTP -1
#define RIGHTP 1

int minAddToMakeValid(char* s) {
    int ret = 0;
    int val = 0;
    for (; *s != '\0'; s++)
    {
        val += *s == '(' ? LEFTP : RIGHTP;
        if (val > 0)
        {
            ret += 1;
            val = 0;
        }
    }
    ret += -val;
    return ret;
}
