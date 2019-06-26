class Solution {
public:
    /**
     * @param s: the maximum length of s is 1000
     * @return: the longest palindromic subsequence's length
     */
    int longestPalindromeSubseq(string &s) {
        // write your code here

        /**
         *
         * dp[i][j]: The length of the longest palindromic subsequence in
         *           the substring starting at the index i and ending at the
         *           index j.
         *
         * dp[i][j] = MAX | if s[i] == s[j], 2 + dp[i + 1][j - 1]
         *                | else, MAX{dp[i + 1][j], dp[i][j - 1]}
         */

        int n = s.length();
        if (n == 0) {
            return 0;
        }

        std::vector<std::vector<int>> dp(n, std::vector<int>(n, 1));

        for (int i = 0 ; i < n - 1 ; ++i) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = 2;
            }
        }

        for (int l = 3 ; l <= n ; ++l) {
            for (int i = 0, j = i + l - 1 ; i <= n - l ; ++i, ++j) {
                int lps = std::max(dp[i + 1][j], dp[i][j - 1]);
                if (s[i] == s[j] && dp[i + 1][j - 1] + 2 > lps) {
                    lps = dp[i + 1][j - 1] + 2;
                }
                dp[i][j] = lps;
            }
        }

        return dp[0][n - 1];
    }
};