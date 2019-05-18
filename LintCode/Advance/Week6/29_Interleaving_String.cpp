class Solution {
public:
    /**
     * @param s1: A string
     * @param s2: A string
     * @param s3: A string
     * @return: Determine whether s3 is formed by interleaving of s1 and s2
     */
    bool isInterleave(string &s1, string &s2, string &s3) {
        // write your code here

        /**
         *  s1: abc
         *  s2: de
         *  s3: adbec
         *
         *  dp[i][j]: Whether we can form the first i + j - 1 alphebats of S3
         *            by using the first i alphebats of S1 and the first j
         *            alphebats of S2.
         *
         *
         *  dp[i][j] = (S1[i - 1] == S3[i + j - 1] && dp[i - 1][j]) ||
         *             (S2[j - 1] == S3[i + j - 1] && dp[i][j - 1])
         *
         */

        int len_s1 = s1.length();
        int len_s2 = s2.length();
        int len_s3 = s3.length();

        if (len_s1 + len_s2 != len_s3) {
            return false;
        }

        bool dp[len_s1 + 1][len_s2 + 1];
        dp[0][0] = true;

        for (int i = 1 ; i <= len_s1 ; ++i) {
            dp[i][0] = (s1[i - 1] == s3[i - 1]);
        }
        for (int i = 1 ; i <= len_s2 ; ++i) {
            dp[0][i] = (s2[i - 1] == s3[i - 1]);
        }

        for (int i = 1 ; i <= len_s1 ; ++i) {
            for (int j = 1 ; j <= len_s2 ; ++j) {
                dp[i][j] = ((s1[i - 1] == s3[i + j - 1]) && dp[i - 1][j]) ||
                           ((s2[j - 1] == s3[i + j - 1]) && dp[i][j - 1]);
            }
        }

        return dp[len_s1][len_s2];
    }
};