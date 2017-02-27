class Solution {
public:
    /**
     * The recursive formula:
     * 
     * Let dp[i][j] : The longest palindromic subsequence found
     *                in substring s(i, j).
     * 
     *                | | dp[i + 1][j - 1] + 2, if s[i] == s[j]
     *                | | 0                   , else for dummy
     * dp[i][j] = MAX | dp[i + 1][j]
     *                | dp[i][j - 1]
     */

    int longestPalindromeSubseq(string s) {
        int length = s.length();
        if (length <= 1) {
            return length;
        }

        std::vector<std::vector<int>> dp(length, std::vector<int>(length, 1));

        for (int i = 0 ; i < length - 1 ; ++i) {
            dp[i][i + 1] = (s[i] == s[i + 1])? 2 : 1;
        }

        for (int l = 2 ; l < length ; ++l) {
            for (int i = 0 ; i < length - l ; ++i) {
                int j = i + l;
                int max;
                max = (s[i] == s[j])? (2 + dp[i + 1][j - 1]) : 0;
                if (dp[i + 1][j] > max) {
                    max = dp[i + 1][j];
                }
                if (dp[i][j - 1] > max) {
                    max = dp[i][j - 1];
                }
                dp[i][j] = max;
            }
        }

        return dp[0][length - 1];
    }
};