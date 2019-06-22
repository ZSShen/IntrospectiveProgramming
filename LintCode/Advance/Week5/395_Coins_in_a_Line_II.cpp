class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        // write your code here

        /**
         *  A: Sa, Diffa = Sa - Sb = (Sa' + n) - Sb' = n - (Sb' - Sa') = n - Diffb'
         *  B: Sb, ...
         *
         *  dp[i]: The maximum value difference a person can get regarding the
         *         remained coins from index i to index n - 1.
         *
         *  dp[i] = MAX{ values[i] - dp[i + 1],
         *               values[i] + values[i + 1] - dp[i + 2] }
         *
         *  dp[n] = 0
         */

        int n = values.size();
        if (n == 0) {
            return false;
        }

        std::vector<int> dp(3, 0);
        dp[n % 3] = 0;

        for (int i = n - 1 ; i >= 0 ; --i) {
            dp[i % 3] = values[i] - dp[(i + 1) % 3];
            if (i < n - 1) {
                dp[i % 3] = std::max(
                    dp[i % 3], values[i] + values[i + 1] - dp[(i + 2) % 3]);
            }
        }

        return dp[0] > 0;
    }
};