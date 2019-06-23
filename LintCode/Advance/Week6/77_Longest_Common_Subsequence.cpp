class Solution {
public:
    /**
     * @param A: A string
     * @param B: A string
     * @return: The length of longest common subsequence of A and B
     */
    int longestCommonSubsequence(string &A, string &B) {
        // write your code here

        /**
         *  dp[i][j]: The LCS of the substrings A(0, i) and B(0, j).
         *
         *  dp[i][j] = | if A[i] == B[j], dp[i - 1][j - 1] + 1
         *             | MAX(dp[i - 1][j], dp[i][j - 1])
         */

        int na = A.size();
        int nb = B.size();

        std::vector<std::vector<int>> dp(na + 1, std::vector<int>(nb + 1, 0));

        for (int i = 1 ; i <= na ; ++i) {
            for (int j = 1 ; j <= nb ; ++j) {
                if (A[i - 1] == B[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[na][nb];
    }
};