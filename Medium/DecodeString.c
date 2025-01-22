bool isLowerAlpha(char s) { return s > 96 && s < 123; }
bool isSBracket(char s) { return s == 91; }
bool isEBracket(char s) { return s == 93; }
bool isDigit(char s) { return s > 47 && s < 58; }

char* backFirstDigit(char* s, char* ssp) {
    int flag = 0;
    for (; isDigit(*s); s--) {
        if (s == ssp)
        {
            flag = 1;
            break;
        }
    }
    if (flag != 1) s++;
    return s;
}

int calNum(char* s) {
    int ret = 0;
    char* ssp = s;
    for (; isDigit(*s); s++) {
        ret = (int)(*s - 48) + ret * 10;
    }
    s = ssp;
    return ret;
}

char* decodeString(char* s) {
    char* ret = malloc(5000 * sizeof(char));
    char* retsp = ret;
    char* tmp = malloc(2500 * sizeof(char));
    char* tmpsp = tmp;
    char* tmpep = tmp;
    int factor = 1;

    while (*s != 0) {
        if (isDigit(*s) || isSBracket(*s) || isLowerAlpha(*s)) {
            *ret = *s;
            ret++, s++;
            continue;
        }

        if (isEBracket(*s)) {
            for (ret--; !isSBracket(*ret); ret--, tmp++) {
                *tmp = *ret;
            }
            tmp--;
            ret--;
            ret = backFirstDigit(ret, retsp);
            factor = calNum(ret);
            for (int i = 0; i < factor; i++) {
                tmpep = tmp;
                for (; tmp >= tmpsp; tmp--) {
                    *ret = *tmp;
                    ret++;
                    if (tmp == tmpsp)
                        break;
                }
                tmp = tmpep;
            }
            tmp = tmpsp;
            s++;
            continue;
        }
    }

    *ret = 0;
    ret = retsp;

    free(tmp);
    return ret;
}
