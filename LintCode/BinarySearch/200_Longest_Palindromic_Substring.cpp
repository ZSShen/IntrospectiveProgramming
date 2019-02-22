class Solution {
public:
    /**
     * @param s: input string
     * @return: the longest palindromic substring
     */
    string longestPalindrome(string &s) {
        // write your code here

        /**
         *
         * Let dp[i][j] record if the substring starting from i and ending at j
         * is a palindromic substring.
         *
         * Objective Function:
         * dp[i][j] = s[i] == s[j] && dp[i + 1][j - 1]
         *
         */

        int size = s.length();
        if (size == 0) {
            return "";
        }

        bool dp[size][size] = {{0}};
        int start = 0, longest = 1;

        for (int i = 0 ; i < size ; ++i) {
            dp[i][i] = true;
        }

        for (int i = 1 ; i < size ; ++i) {
            if (s[i - 1] == s[i]) {
                dp[i - 1][i] = true;
                start = i - 1;
                longest = 2;
            }
        }

        for (int l = 2 ; l < size ; ++l) {
            for (int i = 0, j = i + l ; i < size - l ; ++i, ++j) {
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    start = i;
                    longest = l + 1;
                }
            }
        }

        return s.substr(start, longest);
    }
};