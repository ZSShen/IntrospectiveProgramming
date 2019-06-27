class Solution {
public:
    /**
     * @param A: An integer array
     * @param k: A positive integer (k <= length(A))
     * @param target: An integer
     * @return: An integera
     */
    int kSum(vector<int> &A, int k, int target) {
        // write your code here

        /**
         * dp[i][j][x]: The number of ways to use j items from the
         *              first i items to form x.
         *
         * dp[i][j][x] = | A[i] > x , dp[i - 1][j][x]
         *               | A[i] <= x, dp[i - 1][j][x] + dp[i - 1][j - 1][x - A[i]]
         *
         * Suppose that we have n items in total.
         * Target: dp[n][k][target]
         */

        int n = A.size();
        if (n == 0) {
            return 0;
        }

        std::vector<std::vector<std::vector<int>>>
            dp(n + 1, std::vector<std::vector<int>>(k + 1,
                std::vector<int>(target + 1, 0)));

        for (int i = 0 ; i <= n ; ++i) {
            dp[i][0][0] = 1;
        }

        for (int i = 1 ; i <= n ; ++i) {
            for (int j = 1 ; j <= k && j <= i ; ++j) {
                for (int x = 1 ; x <= target ; ++x) {

                    int item = i - 1;
                    if (A[item] > x) {
                        dp[i][j][x] = dp[i - 1][j][x];
                        continue;
                    }

                    dp[i][j][x] = dp[i - 1][j][x] + dp[i - 1][j - 1][x - A[item]];
                }
            }
        }

        return dp[n][k][target];
    }
};