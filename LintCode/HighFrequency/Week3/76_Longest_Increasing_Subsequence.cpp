class Solution {
public:
    /**
     * @param nums: An integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> &nums) {
        // write your code here

        /**
         *   4, 2, 4, 5, 3, 7
         *
         *  dp[1]: 2
         *  dp[2]: 3
         *  dp[3]: 5
         *  dp[4]: 7
         */

        int n = nums.size();
        if (n == 0) {
            return 0;
        }

        std::vector<int> lis;
        lis.push_back(nums[0]);

        for (int i = 1 ; i < n ; ++i) {
            if (nums[i] > lis.back()) {
                lis.push_back(nums[i]);
                continue;
            }

            int l = 0, r = lis.size() - 1;
            while (l + 1 < r) {
                int m = (l + r) / 2;
                if (nums[i] >= lis[m]) {
                    l = m;
                } else {
                    r = m;
                }
            }

            if (nums[i] < lis[l]) {
                lis[l] = nums[i];
            } else if (nums[i] < lis[r]) {
                lis[r] = nums[i];
            }
        }

        return lis.size();
    }
};