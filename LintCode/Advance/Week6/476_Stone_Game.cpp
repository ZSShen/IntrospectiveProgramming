class Solution {
public:
    /**
     * @param A: An integer array
     * @return: An integer
     */
    int stoneGame(vector<int> &A) {
        // write your code here

        /**
         * dp[i][j]: The minimum cost to merge the piles starting from the
         *           ith pile to the jth pile.
         *
         * dp[i][j] =  MIN { dp[i][k] + dp[k + 1][j] + sum(i, j) }
         *            i<=k<j
         */

        int n = A.size();
        if (n == 0) {
            return 0;
        }

        std::vector<int> prefix(n + 1, 0);
        for (int i = 1 ; i <= n ; ++i) {
            prefix[i] = prefix[i - 1] + A[i - 1];
        }

        std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

        for (int i = 1 ; i < n ; ++i) {
            dp[i - 1][i] = prefix[i + 1] - prefix[i - 1];
        }

        for (int l = 3 ; l <= n ; ++l) {
            for (int i = 0, j = i + l - 1 ; i <= n - l ; ++i, ++j) {
                int min = std::numeric_limits<int>::max();
                int sum = prefix[j + 1] - prefix[i];

                for (int k = i ; k < j ; ++k) {
                    min = std::min(min, dp[i][k] + dp[k + 1][j] + sum);
                }

                dp[i][j] = min;
            }
        }

        return dp[0][n - 1];
    }
};