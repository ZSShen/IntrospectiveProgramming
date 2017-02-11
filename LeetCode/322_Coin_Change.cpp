class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        /**
         *  The recusive fomula:
         * 
         *  Let i     : The amount of money
         *  Let dp[i] : The minimum number of coins used to
         *              compose i
         * 
         * dp[i] = Min{ 1 + dp[i - coins[j]] | 0 <= j < coins.size()}
         */

        std::vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        int category = coins.size();

        for (int i = 1 ; i <= amount ; ++i) {
            int min = INT_MAX;
            for (int j = 0 ; j < category ; ++j) {
                if (coins[j] > i) {
                    continue;
                }
                int base = dp[i - coins[j]];
                if (base == INT_MAX) {
                    continue;
                }

                int change = 1 + base;
                if (change < min) {
                    min = change;
                }
            }

            dp[i] = min;
        }

        return (dp[amount] != INT_MAX)? dp[amount] : (-1);
    }
};