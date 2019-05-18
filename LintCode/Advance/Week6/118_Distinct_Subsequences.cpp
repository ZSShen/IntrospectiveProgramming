class Solution {
public:
    /**
     * @param S: A string
     * @param T: A string
     * @return: Count the number of distinct subsequences
     */
    int numDistinct(string &S, string &T) {
        // write your code here

        /**
         * dp[i][j]: The number of distinct subsequences of the string S[0][i]
         *           that match the string T[0][j].
         *
         *
         * dp[i][j] = | if S[i] == T[j], dp[i - 1][j - 1] + dp[i - 1][j]
         *            | else           , dp[i - 1][j]
         *
         */

        int s = S.length();
        int t = T.length();

        if (s == 0) {
            return 0;
        }
        if (t == 0) {
            return 1;
        }

        int dp[s + 1][t + 1] = {{0}};

        for (int i = 1 ; i <= t ; ++i) {
            dp[0][i] = 0;
        }
        for (int i = 0 ; i <= s ; ++i) {
            dp[i][0] = 1;
        }

        for (int i = 1 ; i <= s ; ++i) {
            for (int j = 1 ; j <= t ; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (S[i - 1] == T[j - 1]) {
                    dp[i][j] += dp[i - 1][j - 1];
                }
            }
        }

        return dp[s][t];
    }
};
