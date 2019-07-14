class Solution {
public:
    /**
     * @param nums: an array with positive and negative numbers
     * @param k: an integer
     * @return: the maximum average
     */
    double maxAverage(vector<int> &nums, int k) {
        // write your code here

        /**
         * Use binary approximation, and then we transform the problem into
         * checking if it is possible to find a subarray whose average sum
         * is equal to or less than T.
         *
         *     A[i] + ... + A[j] / (j - i + 1) >= T , (j - i + 1) >= k
         *  => A[i] + ... + A[j] >= T + ... + T
         *  => (A[i] - T) + ... + (A[j] - T) >= 0
         *  => B[i] + ... + B[j] >= 0               , (j - i + 1) >= k
         *
         *          j             i
         *  -------------------------
         *  | MIN | *     MAX     * |
         *  -------------------------
         */

        int n = nums.size();
        if (n == 0 || k == 0) {
            return 0;
        }

        double l = nums[0], r = nums[0];
        for (int i = 1 ; i < n ; ++i) {
            l = std::min(l, static_cast<double>(nums[i]));
            r = std::max(r, static_cast<double>(nums[i]));
        }

        while (l + 1e-5 < r) {
            double m = l + (r - l) / 2;

            if (canFind(nums, k, n, m)) {
                l = m;
            } else {
                r = m;
            }
        }

        return canFind(nums, k, n, l) ? l : r;
    }

private:
    bool canFind(const auto& nums, int k, int n, double x) {

        double r_sum = 0, l_sum = 0, min_l_sum = 0;

        for (int i = 0 ; i < k ; ++i) {
            r_sum += static_cast<double>(nums[i]) - x;
        }

        for (int i = k ; i < n ; ++i) {
            if (r_sum >= min_l_sum) {
                return true;
            }

            // B[i] ... B[j]
            r_sum += static_cast<double>(nums[i]) - x;
            l_sum += static_cast<double>(nums[i - k]) - x;
            min_l_sum = std::min(min_l_sum, l_sum);
        }

        return r_sum >= min_l_sum;
    }
};