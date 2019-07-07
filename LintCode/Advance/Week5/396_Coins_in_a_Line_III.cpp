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


class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        // write your code here

        /**
         *  A and B, 2 competitors
         *
         *  Sum(i, j): The total value of the remained coins covering from the
         *             ith coin to the jth one.
         *
         *  Sa: The total value A can aggregate in the current iteration.
         *  Sb: The total value B can aggregate in the next iteration.
         *
         *  When there are (j - i + 1) coins remained, player A has 2 choices.
         *      1. Pick the ith coin,
         *          Sa = values[i] + Sum(i + 1, j) - Sb'.
         *             = Sum(i, j) - Sb'.
         *
         *      2. Pick the jth coin,
         *          Sa = values[j] + Sum(i, j - 1) - Sb''.
         *             = Sum(i, j) - Sb''.
         *
         * dp[i][j]: The maximum value that a person can aggregate when there
         *           are (j - i + 1) coins left.
         *
         * dp[i][j] = MAX | pick the ith coin, sum[i][j] - dp[i + 1][j]
         *                | pick the jth coin, sum[i][j] - dp[i][j - 1]
         */

        int n = values.size();
        if (n == 0) {
            return false;
        }
        if (n == 1) {
            return true;
        }

        std::vector<std::vector<int>> sum(n, std::vector<int>(n, 0));
        std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

        for (int i = 0 ; i < n ; ++i) {
            sum[i][i] = values[i];
            dp[i][i] = values[i];
        }

        for (int l = 2 ; l <= n ; ++l) {
            for (int i = 0, j = i + l - 1 ; i <= n - l ; ++i, ++j) {
                sum[i][j] = sum[i][j - 1] + values[j];

                // values[i] + sum[i + 1][j] - dp[i + 1][j]
                int plan_a = sum[i][j] - dp[i + 1][j];

                // values[j] + sum[i][j - 1] - dp[i][j - 1]
                int plan_b = sum[i][j] - dp[i][j - 1];

                dp[i][j] = std::max(plan_a, plan_b);
            }
        }

        return dp[0][n - 1] * 2 > sum[0][n - 1];
    }
};
