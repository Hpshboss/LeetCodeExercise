int arrangeCoins(int n) {
    int rcnt = 1;
    for (; n >= rcnt; rcnt++)
    {
        n -= rcnt;
    }
    rcnt--;
    return rcnt;
}
