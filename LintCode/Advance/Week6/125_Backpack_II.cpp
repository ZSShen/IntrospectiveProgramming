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
         * dp[i][j]: The max values that can be packed into the knapsack which
         *           can hold at max j units of weight using the first i items.
         *
         * dp[i][j] = | MAX{V[i] + dp[i - 1][j - W[i]], dp[i - 1][j]}, if j >= W[i].
         *            | dp[i - 1][j]                                 , else.
         */

        int n = A.size();
        if (n == 0) {
            return 0;
        }

        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));

        for (int i = 1 ; i <= n ; ++i) {
            for (int j = 1 ; j <= m ; ++j) {

                int k = i - 1;
                if (A[k] > j) {
                    dp[i][j] = dp[i - 1][j];
                    continue;
                }
                dp[i][j] = std::max(
                    V[k] + dp[i - 1][j - A[k]], dp[i - 1][j]);
            }
        }

        return dp[n][m];
    }
};