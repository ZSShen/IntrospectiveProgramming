class Solution {
public:
    /*
     * @param A: an integer array
     * @param k: a postive integer <= length(A)
     * @param target: an integer
     * @return: A list of lists of integer
     */
    vector<vector<int>> kSumII(vector<int> &A, int k, int target) {
        // write your code here

        std::vector<std::vector<int>> ans;
        int size = A.size();
        if (size == 0) {
            return ans;
        }

        std::vector<int> collect;
        std::sort(A.begin(), A.end());
        runBacktracking(0, size, A, target, k, collect, ans);
        return ans;
    }

private:
    void runBacktracking(
            int start,
            int bound,
            std::vector<int>& nums,
            int target,
            int k,
            std::vector<int>& collect,
            std::vector<std::vector<int>>& ans) {

        if (k < 0) {
            return;
        }

        if (k == 0 && target == 0) {
            ans.push_back(collect);
            return;
        }

        for (int i = start ; i < bound ; ++i) {
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }

            if (nums[i] > target) {
                break;
            }

            collect.push_back(nums[i]);
            runBacktracking(
                i + 1, bound, nums, target - nums[i], k - 1, collect, ans);
            collect.pop_back();
        }
    }
};