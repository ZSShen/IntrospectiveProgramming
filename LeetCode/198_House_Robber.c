#define MAX(a, b)       ((a > b)? (a) : (b))

int rob(int* nums, int numsSize)  {
    /**
     * Recursive Formula:
     *
     *         | nums[0], if i = 0.
     * dp[i] = | nums[1], if i = 1.
     *         | MAX{ dp[i - 1], MAX{ dp[j] + nums[i] | 0 <= j <= i-2 } }, if i > 1.
     */

    if (numsSize == 0)
        return 0;
    else if (numsSize == 1)
        return nums[0];
    else if (numsSize == 2)
        return MAX(nums[0], nums[1]);

    int dp[numsSize];
    dp[0] = nums[0];
    dp[1] = nums[1];

    int i = 2, j, max, temp;
    while (i < numsSize) {
        max = dp[i - 1];
        j = i - 2;
        while (j >= 0) {
            temp = dp[j] + nums[i];
            if (temp > max)
                max = temp;
            --j;
        }
        dp[i] = max;
        ++i;
    }

    return dp[numsSize - 1];
}