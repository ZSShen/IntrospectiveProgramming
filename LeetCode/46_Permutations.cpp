class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {

        std::vector<std::vector<int>> ans;
        int size = nums.size();
        if (size == 0) {
            return ans;
        }

        runBacktracking(nums, 0, size - 1, ans);
        return ans;
    }


private:
    void runBacktracking(
        std::vector<int>& nums,
        int l, int r,
        std::vector<std::vector<int>>& ans) {

        if (l == r) {
            ans.push_back(nums);
        }

        for (int i = l ; i <= r ; ++i) {
            std::swap(nums[l], nums[i]);
            runBacktracking(nums, l + 1, r, ans);
            std::swap(nums[l], nums[i]);
        }
    }
};