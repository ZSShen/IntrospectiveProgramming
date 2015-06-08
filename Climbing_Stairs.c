int climbStairs(int n) {
    if (n < 0)
        return 0;
    if (n == 0)
        return 1;
    if (n == 1)
        return 1;

    int count_n_2 = 1;
    int count_n_1 = 1;
    int count_n;
    n -= 2;
    while (n >= 0) {
        count_n = count_n_2 + count_n_1;
        count_n_2 = count_n_1;
        count_n_1 = count_n;
        n--;
    }

    return count_n;
}