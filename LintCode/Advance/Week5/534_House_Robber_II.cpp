class Solution {
public:
    /**
     * @param nums: An array of non-negative integers.
     * @return: The maximum amount of money you can rob tonight
     */
    int houseRobber2(vector<int> &nums) {
        // write your code here

        /**
         *  1. Rob the 1st house, solve the problem within the range (0, n - 2)
         *  2. Rob the last house, solve the problem within the range (1, n - 1)
         *
         *
         *  dp[i] = Max | price(i) + dp[i - 2]
         *              | dp[i - 1]
         *
         */

        int size = nums.size();
        if (size == 0) {
            return 0;
        }
        if (size == 1) {
            return nums[0];
        }

        return std::max(rob(nums, 0, size - 2), rob(nums, 1, size - 1));
    }

private:
    int rob(const std::vector<int>& nums, int bgn, int end) {

        int size = nums.size();
        int dp[size] = {0};

        dp[bgn] = nums[bgn];
        dp[bgn + 1] = std::max(nums[bgn], nums[bgn + 1]);

        for (int i = bgn + 2 ; i <= end ; ++i) {
            dp[i] = std::max(nums[i] + dp[i - 2], dp[i - 1]);
        }

        return dp[end];
    }
};