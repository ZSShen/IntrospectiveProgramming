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
         * dp[i][j]: The max values we can get from the first i items with
         *           the knapsack that can hold j units of weight.
         *
         *
         * dp[i][j] = | if W[i] > j, dp[i - 1][j]
         *            | MAX {dp[i - 1][j], V[i] + dp[i][j - W[i]] }
         */

        int n = A.size();
        if (n == 0) {
            return 0;
        }

        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));

        for (int i = 1 ; i <= n ; ++i) {
            for (int j = 1 ; j <= m ; ++j) {

                if (A[i - 1] > j) {
                    dp[i][j] = dp[i - 1][j];
                    continue;
                }

                dp[i][j] = std::max(dp[i - 1][j], V[i - 1] + dp[i][j - A[i - 1]]);
            }
        }

        return dp[n][m];
    }
};