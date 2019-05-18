class Solution {
public:
    /**
     * @param nums: an integer array and all positive numbers, no duplicates
     * @param target: An integer
     * @return: An integer
     */
    int backPackIV(vector<int> &nums, int target) {
        // write your code here

        /**
         * dp[i][j]: The number of ways to pack the backpack with capacity j
         *           using the first i items.
         *
         *
         * dp[i][j] = | if W[i - 1] > j, dp[i - 1][j]
         *            | else           , dp[i][j - W[i - 1]] + dp[i - 1][j]
         */

        int n = nums.size();

        int dp[n + 1][target + 1];

        for (int i = 0 ; i <= n ; ++i) {
            dp[i][0] = 1;
        }
        for (int i = 1 ; i <= target ; ++i) {
            dp[0][i] = 0;
        }

        for (int i = 1 ; i <= n ; ++i) {
            for (int j = 1 ; j <= target ; ++j) {
                if (nums[i - 1] > j) {
                    dp[i][j] = dp[i - 1][j];
                    continue;
                }
                dp[i][j] = dp[i][j - nums[i - 1]] + dp[i - 1][j];
            }
        }

        return dp[n][target];
    }
};