class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        /**
         * The recursive formula:
         * 
         * Let i : Accmulated target number
         * Let j : The index of element array
         * 
         * dp[i] = SUM{ dp[i - nums[j] | i >= nums[j]}
         *         , where 0 <= j < nums.size().
         */

        std::vector<int> dp(target + 1, 0);

        dp[0] = 1;
        for (int i = 1 ; i <= target ; ++i) {
            int comb = 0;
            for (int num : nums) {
                if (i >= num) {
                    comb += dp[i - num];
                }
            }
            dp[i] = comb;
        }

        return dp[target];
    }
};