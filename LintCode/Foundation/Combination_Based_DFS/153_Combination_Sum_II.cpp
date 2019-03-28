class Solution {
public:
    /**
     * @param num: Given the candidate numbers
     * @param target: Given the target number
     * @return: All the combinations that sum to target
     */
    vector<vector<int>> combinationSum2(vector<int> &num, int target) {
        // write your code here

        std::vector<std::vector<int>> ans;
        int size = num.size();
        if (size == 0) {
            return ans;
        }

        std::vector<int> collect;
        std::sort(num.begin(), num.end());
        runBacktracking(0, size, num, target, collect, ans);
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

        if (start == bound) {
            return;
        }

        for (int i = start ; i < bound ; ++i) {
            if (nums[i] > target) {
                break;
            }

            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }

            collect.push_back(nums[i]);
            runBacktracking(i + 1, bound, nums, target - nums[i], collect, ans);
            collect.pop_back();
        }
    }
};