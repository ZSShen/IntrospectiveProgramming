class Solution {
public:
    /**
     * @param word1: A string
     * @param word2: A string
     * @return: The minimum number of steps.
     */
    int minDistance(string &S, string &T) {
        // write your code here

        /**
         *
         * dp[i][j]: The min cost to transform the S[0][i] to T[0][j]
         *
         *            | if S[i] == T[j], dp[i - 1][j - 1]
         * dp[i][j] = | else,   | dp[i - 1][j]
         *                  Min | dp[i - 1][j - 1]  + 1
         *                      | dp[i][j - 1]
         */


        int s = S.length();
        int t = T.length();

        int dp[s + 1][t + 1] = {{0}};

        for (int i = 1 ; i <= s ; ++i) {
            dp[i][0] = i;
        }
        for (int i = 1 ; i <= t ; ++i) {
            dp[0][i] = i;
        }

        for (int i = 1 ; i <= s ; ++i) {
            for (int j = 1 ; j <= t ; ++j) {
                if (S[i - 1] == T[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = std::min(dp[i - 1][j], dp[i - 1][j - 1]);
                    dp[i][j] = std::min(dp[i][j], dp[i][j - 1]) + 1;
                }
            }
        }

        return dp[s][t];
    }
};