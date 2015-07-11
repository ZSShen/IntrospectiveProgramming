/**
 * Recursive Formula:
 *   dp[i][j] = MIN | dp[i][j] + triangle[i][j], if j == 0.
 *                  | dp[i][j - 1] + triangle[i][j], else if j == i.
 *                  | MIN(dp[i][j], dp[i][j - 1]) + triangle[i][j], else.
 *
 * Actually, you can reduce the dimension of "dp" array with the assist of
 * another "memo" array. You do not need to record the complete information
 * from each level. You just need to trace the information with the current
 * and the predecessor level.
 */

#define MIN(a, b)       (((a) < (b))? (a) : (b))


int minimumTotal(int **triangle, int numRows)
{
    if (numRows == 0)
        return 0;
    if (numRows == 1)
        return triangle[0][0];

    int dp[numRows], memo[numRows];
    int i, j;

    dp[0] = triangle[0][0];

    for (i = 1 ; i < numRows ; i++) {
        for (j = 0 ; j <= i ; j++) {
            if (j == 0)
                memo[j] = dp[j] + triangle[i][j];
            else if (j == i)
                memo[j] = dp[j - 1] + triangle[i][j];
            else
                memo[j] = MIN(dp[j], dp[j - 1]) + triangle[i][j];
        }
        for (j = 0 ; j <= i ; j++)
            dp[j] = memo[j];
    }

    int min = dp[0];
    for (i = 1 ; i < numRows ; i++) {
        if (dp[i] < min)
            min = dp[i];
    }

    return min;
}