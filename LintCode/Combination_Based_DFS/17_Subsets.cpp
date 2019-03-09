class Solution {
public:
    /**
     * @param nums: A set of numbers
     * @return: A list of lists
     */
    vector<vector<int>> subsets(vector<int> &nums) {
        // write your code here

        std::vector<std::vector<int>> ans;
        int size = nums.size();
        if (size == 0) {
            ans.push_back(std::vector<int>());
            return ans;
        }

        std::sort(nums.begin(), nums.end());

        std::vector<int> collect;
        runBacktracking(0, size, nums, collect, ans);
        return ans;
    }

private:
    void runBacktracking(
            int start,
            int bound,
            std::vector<int>& nums,
            std::vector<int>& collect,
            std::vector<std::vector<int>>& ans) {

        ans.push_back(collect);

        for (int i = start ; i < bound ; ++i) {
            collect.push_back(nums[i]);
            runBacktracking(i + 1, bound, nums, collect, ans);
            collect.pop_back();
        }
    }
};