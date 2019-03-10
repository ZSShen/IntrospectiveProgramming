class Solution {
public:
    /**
     * @param candidates: A list of integers
     * @param target: An integer
     * @return: A list of lists of integers
     */
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        // write your code here

        std::vector<int> collect;
        std::vector<std::vector<int>> ans;

        int size = candidates.size();
        if (size == 0) {
            return ans;
        }

        std::sort(candidates.begin(), candidates.end());
        runBacktracking(0, size, candidates, target, collect, ans);
        return ans;
    }

private:
    void runBacktracking(
            int start,
            int bound,
            std::vector<int>& nums,
            int target,
            std::vector<int>& collect,
            std::vector<std::vector<int>>& ans) {

        if (target == 0) {
            ans.push_back(collect);
            return;
        }

        for (int i = start ; i < bound ; ++i) {
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }
            if (nums[i] <= target) {
                collect.push_back(nums[i]);
                runBacktracking(i, bound, nums, target - nums[i], collect, ans);
                collect.pop_back();
            }
        }
    }
};