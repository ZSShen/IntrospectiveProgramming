class Solution {
public:
    /**
     * @param A: An array of non-negative integers
     * @return: The maximum amount of money you can rob tonight
     */
    long long houseRobber(vector<int> &A) {
        // write your code here

        /**
         * dp[i]: The maximum profits that we can aggregate from the first i
         *        houses.
         *
         * dp[i] = MAX{ profit[i] + dp[i - 2], dp[i - 1] }
         */

        int n = A.size();
        if (n == 0) {
            return 0;
        }

        std::vector<long long> dp(n, 0);
        dp[0] = A[0];
        dp[1] = std::max(A[0], A[1]);

        for (int i = 2 ; i < n ; ++i) {
            dp[i] = std::max(A[i] + dp[i - 2], dp[i - 1]);
        }

        return dp[n - 1];
    }
};