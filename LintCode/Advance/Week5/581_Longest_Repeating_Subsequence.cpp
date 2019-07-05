class Solution {
public:
    /**
     * @param str: a string
     * @return: the length of the longest repeating subsequence
     */
    int longestRepeatingSubsequence(string &str) {
        // write your code here

        /**
         * dp[i][j]: The length of the longest common subsequence that can
         *           be found in the prefix of str ending at the index i and
         *           the prefix of str ending at the index j.
         *
         * dp[i][j] = | if s[i] == s[j], | if i != j, dp[i - 1][j - 1] + 1
         *            |                  | otherwise, 0
         *            |
         *            | otherwise      , MAX{ dp[i][j - 1], dp[i - 1][j] }
         */

        int n = str.length();
        if (n == 0) {
            return 0;
        }

        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, 0));

        for (int i = 1 ; i <= n ; ++i) {
            for (int j = 1 ; j <= n ; ++j) {
                if (str[i - 1] == str[j - 1] && i != j) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = std::max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }

        return dp[n][n];
    }
};