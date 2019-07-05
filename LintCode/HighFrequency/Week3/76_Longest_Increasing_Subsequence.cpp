class Solution {
public:
    /**
     * @param nums: An integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> &nums) {
        // write your code here

        /**
         *   4 2 4 5 3 7
         *
         *  dp[0] [1] [2] [3]
         *     4
         *     2
         *     2   4
         *     2   4   5
         *     2   3   5
         *     2   3   5   7
         *
         *
         *   O(nlogn)
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

            int cand = nums[i];

            int l = 0, r = lis.size() - 1;
            while (l + 1 < r) {
                int m = (l + r) / 2;
                if (cand >= lis[m]) {
                    l = m;
                } else {
                    r = m;
                }
            }

            if (cand > lis[l]) {
                lis[r] = cand;
            } else {
                lis[l] = cand;
            }
        }

        return lis.size();
    }
};