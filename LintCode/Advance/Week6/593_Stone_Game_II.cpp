class Solution {
public:
    /**
     * @param A: An integer array
     * @return: An integer
     */
    int stoneGame2(vector<int> &A) {
        // write your code here

        /**
         *     A
         *              A good way to break the loop is to flatten the loop
         *  B     E     with 2 consecutive replicas.
         *
         *   C   D      => A B C D E A B C D E
         *
         * dp[i][j]: The minimum cost to merge the piles starting from the
         *           ith pile to the jth pile.
         *
         * dp[i][j] =  MIN { dp[i][k] + dp[k + 1][j] + sum(i, j) }
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

        std::vector<std::vector<int>> dp(nn, std::vector<int>(nn, 0));
        for (int i = 1 ; i < nn ; ++i) {
            dp[i - 1][i] = prefix[i + 1] - prefix[i - 1];
        }

        for (int l = 3 ; l <= n ; ++l) {
            for (int i = 0, j = i + l - 1 ; i <= nn - l ; ++i, ++j) {
                int min = std::numeric_limits<int>::max();
                int sum = prefix[j + 1] - prefix[i];

                for (int k = i ; k < j ; ++k) {
                    min = std::min(min, dp[i][k] + dp[k + 1][j] + sum);
                }

                dp[i][j] = min;
            }
        }

        int ans = std::numeric_limits<int>::max();
        for (int i = 0 ; i < n ; ++i) {
            ans = std::min(ans, dp[i][i + n - 1]);
        }

        return ans;
    }
};