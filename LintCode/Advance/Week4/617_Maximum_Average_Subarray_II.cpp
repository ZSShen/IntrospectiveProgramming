class Solution {
public:
    /**
     * @param nums: an array with positive and negative numbers
     * @param k: an integer
     * @return: the maximum average
     */
    double maxAverage(vector<int> &nums, int k) {
        // write your code here

        if (nums.empty() || k == 0) {
            return 0;
        }

        std::vector<double> reps;
        for (int num : nums) {
            reps.push_back(num);
        }

        double l = reps[0];
        double r = reps[0];
        for (double num : reps) {
            l = std::min(l, num);
            r = std::max(r, num);
        }

        while (l + 1e-5 < r) {
            double m = l + (r - l) / 2;
            if (canFind(reps, k, m)) {
                l = m;
            } else {
                r = m;
            }
        }

        return canFind(reps, k, r) ? r : l;
    }

private:
    bool canFind(std::vector<double>& nums, int k, double x) {

        double r_sum = 0, l_sum = 0, min_l_sum = 0;
        int i, n = nums.size();

        for (i = 0 ; i < k ; ++i) {
            r_sum += nums[i] - x;
        }

        for (i = k ; i <= n ; ++i) {
            if (r_sum - min_l_sum >= 0) {
                return true;
            }

            if (i < n) {
                r_sum += nums[i] - x;
                l_sum += nums[i - k] - x;
                min_l_sum = std::min(min_l_sum, l_sum);
            }
        }

        return false;
    }
};