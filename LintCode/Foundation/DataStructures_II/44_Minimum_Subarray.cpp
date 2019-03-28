class Solution {
public:
    /*
     * @param nums: a list of integers
     * @return: A integer indicate the sum of minimum subarray
     */
    int minSubArray(vector<int> &nums) {
        // write your code here

        /**
         *
         * dp[i] = prefix[i] - MAX {prefix[j]}
         *                     0<=j<=i-1
         */

        int size = nums.size();
        if (size == 0) {
            return 0;
        }

        int prefix_sum = 0, max = 0, ans = INT_MAX;
        for (int num : nums) {
            prefix_sum += num;

            ans = std::min(ans, prefix_sum - max);
            max = std::max(max, prefix_sum);
        }

        return ans;
    }
};