class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        /**
         * Recursive Formula:
         * 
         * Let acc[i][j] : The range sum calculated from "num i" to "num j".
         * 
         * Let dp[i][j]  : The optimal value for elements collected 
         *                 from "num 0" to "num j" with "i cut".
         * 
         * dp[i][j] = MIN{ max(dp[i - 1][k], accu[k + 1][j]) }
         *            , where i - 1 <= k < j.
         */
        
        int sz = nums.size();

        std::vector<std::vector<int>> dp(m, std::vector<int>(sz, 0));
        std::vector<int> acc(sz);

        acc[0] = nums[0];
        dp[0][0] = acc[0];
        for (int i = 1 ; i < sz ; ++i) {
            acc[i] = acc[i - 1] + nums[i];
            dp[0][i] = acc[i];
        }

        for (int i = 1 ; i < m ; ++i) {
            for (int j = i ; j < sz ; ++j) {
                int local = INT_MAX;
                for (int k = i - 1 ; k < j ; ++k) {
                    int test = std::max(dp[i - 1][k],
                        acc[j] - acc[k + 1] + nums[k + 1]);
                    if (test < local) {
                        local = test;
                    }
                }
                dp[i][j] = local;
            }
        }

        return dp[m - 1][sz - 1];
    }
};