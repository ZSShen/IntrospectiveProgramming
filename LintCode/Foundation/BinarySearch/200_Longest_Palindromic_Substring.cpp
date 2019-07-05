class Solution {
public:
    /**
     * @param s: input string
     * @return: the longest palindromic substring
     */
    string longestPalindrome(string &s) {
        // write your code here

        /**
         * palin[i][j]: Whether the substring starting at the index i and
         *              ending at the index j is palindromic.
         *
         * palin[i][j] = s[i] == s[j] && palin[i + 1][j - 1]
         *
         * Since the beginning and the ending offsets already show the
         * length of this palindromic substring, we do not need an extra
         * data structure to record the length information.
         */

        int n = s.length();
        if (n == 0) {
            return "";
        }

        std::vector<std::vector<bool>> palin(n, std::vector<bool>(n, false));

        int lps = 1;
        int bgn = 0;

        for (int i = 0 ; i < n ; ++i) {
            palin[i][i] = true;
            if (i < n - 1) {
                if (s[i] == s[i + 1]) {
                    palin[i][i + 1] = true;
                    lps = 2;
                    bgn = i;
                }
            }
        }

        for (int l = 3 ; l <= n ; ++l) {
            for (int i = 0, j = i + l - 1 ; i <= n - l ; ++i, ++j) {
                if (s[i] == s[j] && palin[i + 1][j - 1]) {
                    palin[i][j] = true;
                    if (l > lps) {
                        lps = l;
                        bgn = i;
                    }
                }
            }
        }

        return s.substr(bgn, lps);
    }
};