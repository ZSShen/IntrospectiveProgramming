class Solution {
public:
    /**
     * @param str: s string
     * @return: return an integer, denote the number of the palindromic substrings
     */
    int countPalindromicSubstrings(string &str) {
        // write your code here

        /**
         *
         * dp[i][j]: Whether the substring starting from i and ending at j
         *           is palindromic.
         *
         * dp[i][j] = str[i] == str[j] && dp[i + 1][j - 1]
         */

        int len = str.length();
        if (len == 0) {
            return 0;
        }

        int count = 0;
        bool dp[len][len] = {{false}};

        for (int l = 0 ; l < len ; ++l) {
            for (int i = 0, j = i + l ; i < len - l ; ++i, ++j) {
                dp[i][j] = str[i] == str[j] && (j - i <= 2 || dp[i + 1][j - 1]);
                if (dp[i][j]) {
                    ++count;
                }
            }
        }

        return count;
    }
};