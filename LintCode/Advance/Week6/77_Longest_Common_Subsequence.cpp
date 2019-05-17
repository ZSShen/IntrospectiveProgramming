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
         *  dp[i][j]: The LCS among the strings A[0][i] and B[0][j].
         *
         *             | if A[i] == B[j], dp[i - 1][j - 1] + 1
         *  dp[i][j] = | else,            Max(dp[i - 1][j], dp[i][j - 1])
         *
         */

        int a = A.length();
        int b = B.length();

        if (a == 0 || b == 0) {
            return 0;
        }

        int dp[a + 1][b + 1] = {{0}};

        for (int i = 1 ; i <= a ; ++i) {
            for (int j = 1 ; j <= b ; ++j) {
                if (A[i - 1] == B[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[a][b];
    }
};