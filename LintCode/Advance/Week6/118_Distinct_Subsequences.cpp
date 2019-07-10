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
         *    0 r a b b b i t
         *  0 1 1 1 1 1 1 1 1
         *  r 0 1 1 1 1 1 1 1
         *  a 0 0 1 1 1 1 1 1
         *  b 0 0 0 1 2 3 3 3
         *  b 0 0 0 0 1 3 3 3
         *  i 0 0 0 0 0 0 3 3
         *  t 0 0 0 0 0 0 0 3
         *
         *  dp[i][j]: The number of distinct ways to form the prefix of T
         *            ending at the jth position by removing any character
         *            of the prefix of S ending at the ith position.
         *
         *  dp[i][j] = | if S[i] == T[j], dp[i - 1][j - 1] + dp[i - 1][j]
         *             | otherwise      , dp[i - 1][j]
         */

        int ns = S.length();
        int nt = T.length();

        std::vector<std::vector<int>> dp(ns + 1, std::vector<int>(nt + 1, 0));
        for (int i = 0 ; i <= ns ; ++i) {
            dp[i][0] = 1;
        }

        for (int i = 1 ; i <= ns ; ++i) {
            for (int j = 1 ; j <= nt ; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (S[i - 1] == T[j - 1]) {
                    dp[i][j] += dp[i - 1][j - 1];
                }
            }
        }

        return dp[ns][nt];
    }
};