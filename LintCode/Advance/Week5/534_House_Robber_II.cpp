class Solution {
public:
    /**
     * @param nums: An array of non-negative integers.
     * @return: The maximum amount of money you can rob tonight
     */
    int houseRobber2(vector<int> &nums) {
        // write your code here

        /**
         *       A      =>  The key to break the loop is generating 2
         *                  subproblems and solving them respectively.
         *   B       E
         *              =>  (A B C D) or (B C D E)
         *     C   D
         *
         *  1. Rob the 1st house, solve the problem within the range (0, n - 2).
         *  2. Rob the last house, solve the problem within the range (1, n - 1).
         *
         *  dp[i]: The maximum profits that we can aggregate from the first
         *         i houses.
         *
         *  dp[i] = MAX { profit[i] + dp[i - 2], dp[i - 1] }
         */

        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return nums[0];
        }

        return std::max(rob(nums, n, 0, n - 2), rob(nums, n, 1, n - 1));
    }

private:
    int rob(const std::vector<int>& nums, int n, int bgn, int end) {

        std::vector<int> dp(n, 0);

        dp[bgn] = nums[bgn];
        dp[bgn + 1] = std::max(nums[bgn], nums[bgn + 1]);

        for (int i = bgn + 2 ; i <= end ; ++i) {
            dp[i] = std::max(nums[i] + dp[i - 2], dp[i - 1]);
        }

        return dp[end];
    }
};
