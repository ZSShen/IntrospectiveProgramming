class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        std::vector<std::vector<int>> ans;
        ans.push_back(std::vector<int>());

        int size = nums.size();
        if (size == 0) {
            return ans;
        }

        std::vector<int> collect;
        for (int i = 1 ; i <= size ; ++i) {
            runBackTracking(0, i, 0, size, nums, collect, ans);
        }

        return ans;
    }

private:
    void runBackTracking(
        int depth,
        int limit,
        int index,
        int size,
        const std::vector<int>& nums,
        std::vector<int>& collect,
        std::vector<std::vector<int>>& ans) {

        if (depth == limit) {
            ans.push_back(collect);
        }

        for (int i = index ; i < size ; ++i) {
            collect.push_back(nums[i]);
            runBackTracking(depth + 1, limit, i + 1, size, nums, collect, ans);
            collect.pop_back();
        }
    }
};