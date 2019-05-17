class Solution {
public:
    /**
     * @param A: An integer array
     * @return: An integer
     */
    int stoneGame(vector<int> &A) {
        // write your code here

        /**
         *  Range(i, j)
         *
         *  dp[i][j]: The min cost to merge the stones in the range (i, j).
         *
         *  dp[i][j] = Min | dp[i][k] + dp[k + 1][j] + sum(i, j)
         *            i<=k<j
         */

        int n = A.size();
        if (n == 0) {
            return 0;
        }

        int prefix[n + 1] = {0};
        for (int i = 1 ; i <= n ; ++i) {
            prefix[i] = prefix[i - 1] + A[i - 1];
        }

        int dp[n][n] = {{0}};
        for (int i = 0 ; i < n ; ++i) {
            dp[i][i] = 0;
        }
        for (int i = 0 ; i < n - 1 ; ++i) {
            dp[i][i + 1] = A[i] + A[i + 1];
        }

        for (int l = 3 ; l <= n ; ++l) {
            for (int i = 0, j = i + l - 1 ; i < n - l + 1 ; ++i, ++j) {
                dp[i][j] = std::numeric_limits<int>::max();
                int sum = prefix[j + 1] - prefix[i];

                for (int k = i ; k < j ; ++k) {
                    dp[i][j] = std::min(
                        dp[i][j], dp[i][k] + dp[k + 1][j] + sum);
                }
            }
        }

        return dp[0][n - 1];
    }
};