class Solution {
public:
    /**
     * @param nums: an array
     * @param k: an integer
     * @return: the maximum average value
     */
    double findMaxAverage(vector<int> &nums, int k) {
        // Write your code here

        /**
         *   1, 12, -5, -6, 50,  3
         *
         *   k = 4
         *
         *           l           r
         *   1, 13,  8,  2, 52, 55
         *
         */

        int n = nums.size();
        if (n == 0) {
            return 0;
        }

        std::vector<long> prefix(n + 1);
        prefix[0] = 0;
        for (int i = 0 ; i < n ; ++i) {
            prefix[i + 1] = nums[i] + prefix[i];
        }

        double ans = static_cast<double>(prefix[k] - prefix[0]) / k;
        for (int i = k + 1, j = 1 ; i <= n ; ++i, ++j) {
            ans = std::max(ans, static_cast<double>(prefix[i] - prefix[j]) / k);
        }

        return ans;
    }
};