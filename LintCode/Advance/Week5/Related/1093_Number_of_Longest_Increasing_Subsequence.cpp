class Solution {
public:
    /**
     * @param nums: an array
     * @return: the number of longest increasing subsequence
     */
    int findNumberOfLIS(vector<int> &nums) {
        // Write your code here

        /**
         * dp[i]: The last position the (i + 1)th number can be put in.
         *
         * count[i]: The number of ISes which use the (i + 1)th number as
         *           the tail.
         *
         *  O(n^2)
         */

        int n = nums.size();
        if (n == 0) {
            return 0;
        }

        std::vector<int> dp(n, 0);
        std::vector<int> count(n, 0);
        int lis = 1;

        dp[0] = 1;
        ++count[0];

        for (int i = 1 ; i < n ; ++i) {
            int best = 0;
            int num = 1;
            for (int j = i - 1 ; j >= 0 ; --j) {
                if (nums[i] > nums[j]) {
                    if (dp[j] > best) {
                        best = dp[j];
                        num = count[j];
                    } else if (dp[j] == best) {
                        num += count[j];
                    }
                }
            }

            ++best;
            lis = std::max(lis, best);
            dp[i] = best;
            count[i] = num;
        }

        int sum = 0;
        for (int i = 0 ; i < n ; ++i) {
            if (dp[i] == lis) {
                sum += count[i];
            }
        }

        return sum;
    }
};