class Solution {
public:
    /*
     * @param A: an integer array
     * @param k: a postive integer <= length(A)
     * @param target: an integer
     * @return: A list of lists of integer
     */
    vector<vector<int>> kSumII(vector<int> &cands, int k, int target) {
        // write your code here

        int n = cands.size();
        if (n == 0) {
            return {};
        }

        std::sort(cands.begin(), cands.end());

        std::vector<int> collect;
        std::vector<std::vector<int>> ans;
        runBackTracking(cands, 0, n, 0, k, target, collect, ans);

        return ans;
    }

private:
    void runBackTracking(
            const std::vector<int>& cands,
            int index, int bound, int depth, int k,
            int target,
            std::vector<int>& collect,
            std::vector<std::vector<int>>& ans) {

        if (depth == k) {
            if (target == 0) {
                ans.push_back(collect);
            }
            return;
        }

        for (int i = index ; i < bound ; ++i) {
            if (cands[i] > target) {
                break;
            }

            collect.push_back(cands[i]);
            runBackTracking(
                cands, i + 1, bound, depth + 1, k, target - cands[i], collect, ans);
            collect.pop_back();
        }
    }
};