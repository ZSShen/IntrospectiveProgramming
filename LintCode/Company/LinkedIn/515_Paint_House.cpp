class Solution {
public:
    /**
     * @param costs: n x 3 cost matrix
     * @return: An integer, the minimum cost to paint all houses
     */
    int minCost(vector<vector<int>> &costs) {
        // write your code here

        /**
         * dp[i][R,G,B]: The minimum cost to paint the first i houses with
         *               the ith house painted using red, green, or blue.
         *
         * dp[i][R] = cost[i][R] + MIN(dp[i - 1][G], dp[i - 1][B])
         * dp[i][G] = cost[i][G] + MIN(dp[i - 1][R], dp[i - 1][B])
         * dp[i][B] = cost[i][B] + MIN(dp[i - 1][R], dp[i - 1][G])
         */

        int n = costs.size();
        if (n == 0) {
            return 0;
        }

        std::vector<std::vector<int>> dp(n, std::vector<int>(3, 0));

        dp[0][0] = costs[0][0];
        dp[0][1] = costs[0][1];
        dp[0][2] = costs[0][2];

        for (int i = 1 ; i < n ; ++i) {
            dp[i][0] = costs[i][0] + std::min(dp[i - 1][1], dp[i - 1][2]);
            dp[i][1] = costs[i][1] + std::min(dp[i - 1][0], dp[i - 1][2]);
            dp[i][2] = costs[i][2] + std::min(dp[i - 1][0], dp[i - 1][1]);
        }

        return std::min(std::min(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]);
    }
};