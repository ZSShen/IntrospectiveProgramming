class Solution {
public:
    /**
     * @param K: An integer
     * @param prices: An integer array
     * @return: Maximum profit
     */
    int maxProfit(int k, vector<int> &prices) {
        // write your code here

        /**
         * dp[i][j]: The maximum profits that we can get after we conduct at
         *           most i transactions in the first j days.
         *
         * dp[i][j] = MAX | no transaction on the jth day, dp[i][j - 1]
         *                | otherwise,
         *                |     MAX { (price[j] - price[h]) + dp[i - 1][h] }
         *                     0<=h<j
         *      O(k * n^2)
         *
         * NOTE: Too many redundant computations here!
         *
         *   MAX { (price[j] - price[h]) + dp[i - 1][h] }
         *  0<=h<j
         *
         *  In each day, we compare all the transaction values among the first
         *  j - 1 days to determine the maximum profit for today. However, we
         *  can use a cache to keep the maximum profit that can be aggregated
         *  from the first j - 1 days. Hence, to decide the maximum profit for
         *  today, we can compare that cache with the transaction made today,
         *  thus reducing the complexity.
         *
         *   (price[j] - price[h]) + dp[i - 1][h]
         *   price[j] + (dp[i - 1][h] -  price[h])
         *              ^^^^^^^^^^^^^^^^^^^^^^^^^^ can be cached!
         *
         *  => price[j] + MaxDiff, determine the optimal value
         *  => MaxDiff = MAX{ MaxDiff, dp[i - 1][j] - price[j]}, update the cache
         *
         *      O(kn)
         */

        int n = prices.size();
        if (n == 0 || k == 0) {
            return 0;
        }

        if (k >= n / 2) {
            int sum = 0;
            for (int i = 1 ; i < n ; ++i) {
                if (prices[i] > prices[i - 1]) {
                    sum += prices[i] - prices[i - 1];
                }
            }
            return sum;
        }

        std::vector<std::vector<int>> dp(k + 1, std::vector<int>(n, 0));

        /*
            O(k * n^2)

        for (int i = 1 ; i <= k ; ++i) {
            for (int j = 1 ; j < n ; ++j) {
                int max = dp[i][j - 1];

                for (int h = 0 ; h < j ; ++h) {
                    max = std::max(max, dp[i - 1][h] +  prices[j] - prices[h]);
                }

                dp[i][j] = max;
            }
        }
        */

        // O(kn) with cache

        for (int i = 1 ; i <= k ; ++i) {
            int max_diff = -prices[0];

            for (int j = 1 ; j < n ; ++j) {
                // Determine the optimal value.
                dp[i][j] = std::max(dp[i][j - 1], prices[j] + max_diff);

                // Update the cache.
                max_diff = std::max(max_diff, dp[i - 1][j] - prices[j]);
            }
        }

        return dp[k][n - 1];
    }
};