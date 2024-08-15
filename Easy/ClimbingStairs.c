int climbStairs(int n) {
    if (n == 0) return 1;

    return n > 1 ? climbStairs(n-1) + climbStairs(n-2) : climbStairs(n-1);
}
