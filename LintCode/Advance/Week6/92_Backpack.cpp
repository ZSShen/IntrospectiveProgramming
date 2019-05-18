class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> &A) {
        // write your code here

        /**
         * dp[i][j]: Whether it is possible to collect the items among the
         *           first i items whose total weight is equal to j.
         *
         * dp[i][j] = | if j >= item[i], dp[i - 1][j - item[i]] or dp[i - 1][j]
         *            | else           , dp[i - 1][j]
         */

        int n = A.size();
        if (n == 0) {
            return 0;
        }

        bool dp[n + 1][m + 1];

        dp[0][0] = true;
        for (int i = 1 ; i <= n ; ++i) {
            dp[i][0] = true;
        }
        for (int i = 1 ; i <= m ; ++i) {
            dp[0][i] = false;
        }

        int ans = 0;
        for (int i = 1 ; i <= n ; ++i) {
            for (int j = 1 ; j <= m ; ++j) {

                dp[i][j] = dp[i - 1][j];
                if (j >= A[i - 1]) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j - A[i - 1]];
                }

                if (dp[i][j]) {
                    ans = std::max(ans, j);
                }
            }
        }

        return ans;
    }
};