class Solution {
public:
    /**
     * @param A: A string
     * @param B: A string
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
        // write your code here

        int a = A.length();
        int b = B.length();

        if (a == 0 || b == 0) {
            return 0;
        }

        int dp[a + 1][b + 1] = {{0}};
        int ans = 0;

        for (int i = 1 ; i <= a ; ++i) {
            for (int j = 1 ; j <= b ; ++j) {
                if (A[i - 1] == B[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    ans = std::max(ans, dp[i][j]);
                }
            }
        }

        return ans;
    }
};