class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        std::vector<std::vector<int>> ans;
        int size = nums.size();
        if (size == 0) {
            return ans;
        }

        std::sort(nums.begin(), nums.end());

        ans.push_back(std::vector<int>());
        std::vector<int> prefix;
        for (int i = 0 ; i < size ; ++i) {
            runBacktracking(0, size, 0, i + 1, nums, prefix, ans);
        }

        return ans;
    }

private:
    void runBacktracking(
            int base,
            int bound,
            int count,
            int total,
            std::vector<int>& nums,
            std::vector<int>& prefix,
            std::vector<std::vector<int>>& ans) {

        if (count == total) {
            ans.push_back(prefix);
            return;
        }

        for (int i = base ; i < bound ; ++i) {
            if (i != base && nums[i] == nums[i - 1]) {
                continue;
            }

            prefix.push_back(nums[i]);
            runBacktracking(i + 1, bound, count + 1, total, nums, prefix, ans);
            prefix.pop_back();
        }
    }
};