class Solution {
public:
    /**
     * @param str: a string
     * @return: the length of the longest repeating subsequence
     */
    int longestRepeatingSubsequence(string &str) {
        // write your code here

        /**
         * dp[i][j]: The length of the LRS of the substrings s(0, i) andvs(0, j).
         *
         * dp[i][j] = | dp[i - 1][j - 1] + 1           ,if s[i] == s[j], i != j.
         *            | MAX{dp[i][j - 1], dp[i - 1][j]}, else
         */

        int n = str.length();
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