class Solution {
public:
    /**
     * @param A: A string
     * @param B: A string
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
        // write your code here

        /**
         * dp[i][j]: The length of the longest common substring of the 2
         *           prefixes A(0, i) and B(0, j).
         *
         * dp[i][j] = | if A[i] == B[j], 1 + dp[i - 1][j - 1]
         *            | Otherwise      , 0
         *
         *
         *  e.g.: ABCD, CBCE
         *
         *      0 A B C D
         *    0 0 0 0 0 0
         *    C 0 0 0 1 0
         *    B 0 0 1 0 0
         *    C 0 0 0 2 0
         *    E 0 0 0 0 0
         */

        int na = A.size();
        int nb = B.size();

        int ans = 0;
        std::vector<std::vector<int>> dp(na + 1, std::vector<int>(nb + 1, 0));

        for (int i = 1 ; i <= na ; ++i) {
            for (int j = 1 ; j <= nb ; ++j) {
                if (A[i - 1] == B[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    ans = std::max(ans, dp[i][j]);
                }
            }
        }

        return ans;
    }
};