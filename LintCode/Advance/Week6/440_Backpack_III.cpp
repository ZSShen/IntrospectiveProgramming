class Solution {
public:
    /**
     * @param A: an integer array
     * @param V: an integer array
     * @param m: An integer
     * @return: an array
     */
    int backPackIII(vector<int> &A, vector<int> &V, int m) {
        // write your code here

        /**
         *
         * dp[i][j]: The max value we can get among the first i items when we
         *           use the knapsack with j units of capacity.
         *
         *
         * dp[i][j] = | if A[i - 1] > j, dp[i - 1][j]
         *            | else           , Max | dp[i][j - A[i - 1]] + V[i - 1]
         *                                   | dp[i - 1][j]
         */

        int n = A.size();
        if (n == 0) {
            return 0;
        }

        int dp[n + 1][m + 1];

        dp[0][0] = 0;
        for (int i = 1 ; i <= n ; ++i) {
            dp[i][0] = 0;
        }
        for (int i = 1 ; i <= m ; ++i) {
            dp[0][i] = 0;
        }

        for (int i = 1 ; i <= n ; ++i) {
            for (int j = 1 ; j <= m ; ++j) {
                if (A[i - 1] > j) {
                    dp[i][j] = dp[i - 1][j];
                    continue;
                }

                dp[i][j] = std::max(
                    dp[i][j - A[i - 1]] + V[i - 1], dp[i - 1][j]);
            }
        }

        return dp[n][m];
    }
};