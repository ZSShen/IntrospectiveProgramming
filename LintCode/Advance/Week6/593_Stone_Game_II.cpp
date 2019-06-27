class Solution {
public:
    Solution()
      : int_max(std::numeric_limits<int>::max())
    { }

    /**
     * @param A: An integer array
     * @return: An integer
     */
    int stoneGame2(vector<int> &A) {
        // write your code here

        /**
         *     A
         *  B     C
         *           => A B C D E => A B C D E A B C D E
         *   D   E
         *
         * dp[i][j]: The min number of scores that we can get from the
         *           ith pile to the jth pile.
         *
         * dp[i][j] =  MIN { dp[i][k] + dp[k+1][j] + sum(i, j) }
         *            i<=k<j
         */

        int n = A.size();
        if (n == 0) {
            return 0;
        }

        int nn = n * 2;

        std::vector<int> prefix(nn + 1, 0);
        for (int i = 1 ; i <= nn ; ++i) {
            prefix[i] = prefix[i - 1] + A[i - 1];

            if (i <= n) {
                A.push_back(A[i - 1]);
            }
        }

        std::vector<std::vector<int>> dp(nn, std::vector<int>(nn, int_max));
        for (int i = 0 ; i < nn ; ++i) {
            dp[i][i] = 0;
            if (i < nn  - 1) {
                dp[i][i + 1] = A[i] + A[i + 1];
            }
        }

        for (int l = 3 ; l <= nn ; ++l) {
            for (int i = 0, j = i + l - 1 ; i <= nn - l ; ++i, ++j) {
                for (int k = i ; k < j ; ++k) {
                    dp[i][j] = std::min(
                        dp[i][j],
                        dp[i][k] + dp[k + 1][j] + prefix[j + 1] - prefix[i]);
                }
            }
        }

        int ans = int_max;
        for (int i = 0 ; i < n ; ++i) {
            ans = std::min(ans, dp[i][i + n - 1]);
        }

        return ans;
    }

private:
    int int_max;
};
