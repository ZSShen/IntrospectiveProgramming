class Solution {
public:
    /*
     * @param nums: a sorted integer array
     * @param lower: An integer
     * @param upper: An integer
     * @return: a list of its missing ranges
     */
    vector<string> findMissingRanges(vector<int> &nums, int lower, int upper) {
        // write your code here

        if (nums.empty()) {
            return {generateRange(lower, upper)};
        }

        std::vector<std::string> ans;

        if (lower < nums[0]) {
            ans.push_back(generateRange(lower, nums[0] - 1));
        }

        int n = nums.size();
        for (int i = 1 ; i < n ; ++i) {
            long diff = static_cast<long>(nums[i]) - nums[i - 1];

            if (diff <= 1) {
                continue;
            }
            ans.push_back(generateRange(nums[i - 1] + 1, nums[i] - 1));
        }

        if (upper > nums[n - 1]) {
            ans.push_back(generateRange(nums[n - 1] + 1, upper));
        }

        return ans;
    }

private:
    std::string generateRange(int bgn, int end) {

        if (bgn == end) {
            return std::to_string(bgn);
        } else {
            return std::to_string(bgn) + "->" + std::to_string(end);
        }
    }
};