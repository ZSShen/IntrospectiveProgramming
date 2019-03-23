class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> &nums) {
        // write your code here

        /**
         *  DP formula:
         *
         *  dp[i] = prefix[i] - MIN {prefix[j]}
         *                      0<=j<=i-1
         */

        int size = nums.size();
        if (size == 0) {
            return 0;
        }

        int prefix_sum = 0, min = 0, ans = INT_MIN;
        for (int num : nums) {
            prefix_sum += num;
            ans = std::max(ans, prefix_sum - min);
            min = std::min(min, prefix_sum);
        }

        return ans;
    }
};