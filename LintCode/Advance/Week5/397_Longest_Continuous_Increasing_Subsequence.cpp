class Solution {
public:
    /**
     * @param A: An array of Integer
     * @return: an integer
     */
    int longestIncreasingContinuousSubsequence(vector<int> &A) {
        // write your code here

        /**
         *  dp[i]: The length of the current continuous subsequence (substring)
         *         ending at the index i.
         *
         *  dp[i] = | if A[i] > A[i + 1] , dp[i] = dp[i - 1] + 1.
         *          | otherwise          , dp[i] = 1.
         */

        int n = A.size();
        if (n == 0) {
            return 0;
        }

        int ans = 1;
        int dp = 1;
        for (int i = 1 ; i < n ; ++i) {
            if (A[i] > A[i - 1]) {
                ++dp;
                ans = std::max(ans, dp);
            } else {
                dp = 1;
            }
        }

        dp = 1;
        for (int i = n - 2 ; i >= 0 ; --i) {
            if (A[i] > A[i + 1]) {
                ++dp;
                ans = std::max(ans, dp);
            } else {
                dp = 1;
            }
        }

        return ans;
    }
};