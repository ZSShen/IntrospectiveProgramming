class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        // write your code here

        /**
         *  Sa: The total values that A can get.
         *  Sb: The total values that B can get.
         *
         *  For a coin m.
         *
         *  Diffa = Sa - Sb' = (m + Sa') - Sb' = m - (Sb' - Sa') = m - Diffb'
         *  Diffb = Sb - Sa  = ...                               = m - Diffa'
         *
         *  dp[i][j]: The max value difference that a person at the current
         *            round can get if he needs to choose a coin among the
         *            ith coin to the jth coin.
         *
         *  dp[i][j] = MAX{values[i] - dp[i + 1][j], values[j] - dp[i][j - 1]}
         *
         *  dp[0][n - 1] > 0
         *
         */

        int n = values.size();
        if (n == 0) {
            return false;
        }

        std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));
        for (int i = 0 ; i < n ; ++i) {
            dp[i][i] = values[i];
        }

        for (int l = 2 ; l <= n ; ++l) {
            for (int i = 0, j = i + l - 1 ; i <= n - l ; ++i, ++j) {
                dp[i][j] = std::max(
                    values[i] - dp[i + 1][j], values[j] - dp[i][j - 1]);
            }
        }

        return dp[0][n - 1] > 0;
    }
};
