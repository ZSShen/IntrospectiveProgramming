class Solution {
public:
    /**
     * @param nums: A list of integer
     * @return: An integer, maximum coins
     */
    int maxCoins(vector<int> &nums) {
        // write your code here

        /**
         * | ........ B ....... |
         * | .... B ........... |
         * | ............ B ... |
         *
         * dp[i][j]: The maximum score that we can secure among the ith balloon
         *           to the jth balloon.
         *
         * Consider k is the last balloon that we can burst among the range(i, j).
         *
         * dp[i][j] =  MAX { dp[i][k - 1] + dp[k + 1][j] + nums[i - 1] * nums[k] * nums[j + 1} }
         *           i<=k<=j
         */

        int n = nums.size();
        if (n == 0) {
            return 0;
        }

        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        std::vector<std::vector<int>> dp(n + 2, std::vector<int>(n + 2, 0));

        for (int l = 1 ; l <= n ; ++l) {
            for (int i = 1, j = i + l - 1 ; i <= n - l + 1 ; ++i, ++j) {
                int max = 0;

                for (int k = i ; k <= j ; ++k) {
                    max = std::max(
                        max, dp[i][k - 1] + dp[k + 1][j] + nums[i - 1] * nums[k] * nums[j + 1]);
                }

                dp[i][j] = max;
            }
        }

        return dp[1][n];
    }
};
