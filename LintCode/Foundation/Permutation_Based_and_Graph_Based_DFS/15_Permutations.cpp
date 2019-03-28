class Solution {
public:
    /*
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    vector<vector<int>> permute(vector<int> &nums) {
        // write your code here

        std::vector<std::vector<int>> ans;
        int size = nums.size();
        if (size == 0) {
            ans.push_back(std::vector<int>());
            return ans;
        }

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

            visit[i] = true;
            perm.push_back(nums[i]);
            runBacktracking(count + 1, bound, nums, visit, perm, ans);
            perm.pop_back();
            visit[i] = false;
        }
    }
};