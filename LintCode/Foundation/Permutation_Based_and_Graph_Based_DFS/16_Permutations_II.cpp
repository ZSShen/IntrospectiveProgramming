class Solution {
public:
    /*
     * @param :  A list of integers
     * @return: A list of unique permutations
     */
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        // write your code here

        int n = nums.size();
        if (n == 0) {
            return {{}};
        }

        std::sort(nums.begin(), nums.end());

        std::vector<bool> use(n, false);
        std::vector<int> perm;
        std::vector<std::vector<int>> ans;
        runBackTracking(nums, 0, n, use, perm, ans);

        return ans;
    }


private:
    void runBackTracking(
            const std::vector<int>& nums,
            int depth, int bound,
            std::vector<bool>& use,
            std::vector<int>& perm,
            std::vector<std::vector<int>>& ans) {

        if (depth == bound) {
            ans.push_back(perm);
            return;
        }

        for (int i = 0 ; i < bound ; ++i) {
            if (use[i]) {
                continue;
            }
            if (i > 0 && nums[i] == nums[i - 1] && !use[i - 1]) {
                continue;
            }

            use[i] = true;
            perm.push_back(nums[i]);
            runBackTracking(nums, depth + 1, bound, use, perm, ans);
            perm.pop_back();
            use[i] = false;
        }
    }
};