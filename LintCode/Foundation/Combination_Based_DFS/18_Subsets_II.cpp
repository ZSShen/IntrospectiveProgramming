class Solution {
public:
    /**
     * @param nums: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        // write your code here
        
        int size = nums.size();
        if (size == 0) {
            return {{}};
        }
        
        std::sort(nums.begin(), nums.end());
        
        std::vector<std::vector<int>> ans;
        std::vector<int> prefix;
        
        runBacktracking(0, size, nums, prefix, ans);
        return ans;
    }

private:
    void runBacktracking(
            int bgn,
            int end,
            const std::vector<int>& nums,
            std::vector<int>& prefix,
            std::vector<std::vector<int>>& ans) {
        
        ans.push_back(prefix);
        
        /**
         * 1 2a 2b 2c:
         * 
         * (1, 2a, 2b)
         * (1, 2a, 2c)
         * 
         */
        
        for (int i = bgn ; i < end ; ++i) {
            if (i > 0 && nums[i] == nums[i - 1] && i > bgn) {
                continue;
            }
            prefix.push_back(nums[i]);
            runBacktracking(i + 1, end, nums, prefix, ans);
            prefix.pop_back();
        }
    }
};