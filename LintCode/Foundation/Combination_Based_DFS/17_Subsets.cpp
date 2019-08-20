class Solution {
public:
    /**
     * @param nums: A set of numbers
     * @return: A list of lists
     */
    vector<vector<int>> subsets(vector<int> &nums) {
        // write your code here

        int n = nums.size();
        if (n == 0) {
            return {{}};
        }

        std::sort(nums.begin(), nums.end());

        std::vector<int> collect;
        std::vector<std::vector<int>> ans;
        for (int i = 0 ; i <= n ; ++i) {
            runBackTracking(nums, 0, n, 0, i, collect, ans);
        }

        return ans;
    }

private:
    void runBackTracking(
            const std::vector<int>& nums,
            int index, int bound,
            int k, int n,
            std::vector<int>& collect,
            std::vector<std::vector<int>>& ans) {

        if (k == n) {
            ans.push_back(collect);
            return;
        }

        for (int i = index ; i < bound ; ++i) {
            collect.push_back(nums[i]);
            runBackTracking(nums, i + 1, bound, k + 1, n, collect, ans);
            collect.pop_back();
        }
    }
};