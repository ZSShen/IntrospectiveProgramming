class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here

        /**
         * 1 7 2 4 5 6 1
         *
         *   *
         *   *       *
         *   *     * *
         *   *   * * *
         *   *   * * *
         *   * * * * *
         * * * * * * * *
         * _____________
         *
         */

        int n = prices.size();
        if (n == 0) {
            return 0;
        }

        int ans = 0;
        int bgn = 0, end = 1;

        while (end < n) {
            if (prices[end] >= prices[end - 1]) {
                ++end;
                continue;
            }

            ans += prices[end - 1] - prices[bgn];
            bgn = end;
            ++end;
        }
        ans += prices[end - 1] - prices[bgn];


        return ans;
    }
};