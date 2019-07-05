class Solution {
public:
    /**
     * @param s: the maximum length of s is 1000
     * @return: the longest palindromic subsequence's length
     */
    int longestPalindromeSubseq(string &s) {
        // write your code here

        /**
         * dp[i][j]: The length of the longest palindromic subsequence in
         *           the substring starting at the index i and ending at the
         *           index j.
         *
         * dp[i][j] = | if s[i] == s[j], 2 + dp[i + 1][j - 1]
         *            | otherwise      , max{ dp[i][j - 1], dp[i + 1][j] }
         */

        int n = s.length();
        if (n == 0) {
            return 0;
        }

        std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

        for (int i = 0 ; i < n ; ++i) {
            dp[i][i] = 1;
        }

        for (int l = 2 ; l <= n ; ++l) {
            for (int i = 0, j = i + l - 1 ; i <= n - l ; ++i, ++j) {
                if (s[i] == s[j]) {
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                } else {
                    dp[i][j] = std::max(dp[i][j - 1], dp[i + 1][j]);
                }
            }
        }

        return dp[0][n - 1];
    }
};