#define ALLCAP 0x01
#define NONCAP 0x02
#define FIRCAP 0x04

#define ISCAP(a) a > 64 ? a < 91 ? true : false : false

bool detectCapitalUse(char* word) {
    int stat = ALLCAP | NONCAP | FIRCAP;

    if (ISCAP(*word))
        stat &= ~NONCAP;
    else
        stat &= ~(ALLCAP | FIRCAP);

    for (word++; *word != '\0'; word++)
    {
        if (ISCAP(*word))
        {
            if (stat & NONCAP)
                stat &= ~NONCAP;
            if (stat & FIRCAP)
                stat &= ~FIRCAP;
        }
        else
        {
            if (stat & ALLCAP)
                stat &= ~ALLCAP;
        }
    }

    if (stat == 0)
        return false;

    return true;
}
