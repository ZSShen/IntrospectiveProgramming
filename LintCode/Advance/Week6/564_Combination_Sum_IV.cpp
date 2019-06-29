class Solution {
public:
    /**
     * @param nums: an integer array and all positive numbers, no duplicates
     * @param target: An integer
     * @return: An integer
     */
    int backPackVI(vector<int> &nums, int target) {
        // write your code here

        /**
         * dp[i]: The number of ways to sum up to i using any combination of numbers.
         *
         * dp[i] =  SUM { dp[i - nums[j] | i >= nums[j]}
         *         0<=j<n
         *
         *         n is the amount of numbers.
         */

        int n = nums.size();
        if (n == 0) {
            return 0;
        }

        std::vector<int> dp(target + 1, 0);
        dp[0] = 1;

        for (int i = 1 ; i <= target ; ++i) {
            for (int num : nums) {
                if (num > i) {
                    continue;
                }
                dp[i] += dp[i - num];
            }
        }

        return dp[target];
    }
};
