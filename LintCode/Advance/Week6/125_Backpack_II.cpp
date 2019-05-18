class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @param V: Given n items with value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> &A, vector<int> &V) {
        // write your code here

        /**
         *  dp[i][j]: The max value that we can collect among the first i
         *            items with the knapsack that can hold j units of weight.
         *
         *
         *  dp[i][j] = | if A[i - 1] <= j, Max | dp[i - 1][j - A[i - 1]] + V[i - 1],
         *             |                       | dp[i - 1][j])
         *             | else            , dp[i - 1][j]
         */

        int n = A.size();

        if (n == 0 || m == 0) {
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
                    dp[i - 1][j - A[i - 1]] + V[i - 1], dp[i - 1][j]);
            }
        }

        return dp[n][m];
    }
};