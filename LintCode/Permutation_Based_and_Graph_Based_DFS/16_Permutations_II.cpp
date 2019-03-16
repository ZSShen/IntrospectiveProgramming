class Solution {
public:
    /*
     * @param :  A list of integers
     * @return: A list of unique permutations
     */
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        // write your code here

        std::vector<std::vector<int>> ans;
        int size = nums.size();
        if (size == 0) {
            ans.push_back(std::vector<int>());
            return ans;
        }

        std::sort(nums.begin(), nums.end());

        std::vector<bool> visit(size, false);
        std::vector<int> perm;
        runBacktracking(0, size, nums, visit, perm, ans);

        return ans;
    }

private:
    void runBacktracking(
            int count,
            int bound,
            const std::vector<int>& nums,
            std::vector<bool>& visit,
            std::vector<int>& perm,
            std::vector<std::vector<int>>& ans) {

        if (count == bound) {
            ans.push_back(perm);
            return;
        }

        for (int i = 0 ; i < bound ; ++i) {
            if (visit[i]) {
                continue;
            }

            if (i > 0 && nums[i - 1] == nums[i] && !visit[i - 1]) {
                continue;
            }

            perm.push_back(nums[i]);
            visit[i] = true;
            runBacktracking(count + 1, bound, nums, visit, perm, ans);
            perm.pop_back();
            visit[i] = false;
        }
    }
};