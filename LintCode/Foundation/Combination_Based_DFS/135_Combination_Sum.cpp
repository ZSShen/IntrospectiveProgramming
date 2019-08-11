class Solution {
public:
    /**
     * @param candidates: A list of integers
     * @param target: An integer
     * @return: A list of lists of integers
     */
    vector<vector<int>> combinationSum(vector<int> &cands, int target) {
        // write your code here

        int n = cands.size();
        if (n == 0) {
            return {};
        }

        std::sort(cands.begin(), cands.end());

        std::vector<int> collect;
        std::vector<std::vector<int>> ans;
        runBackTracking(cands, 0, 0, n, target, collect, ans);

        return ans;
    }

private:
    void runBackTracking(
            const std::vector<int>& cands,
            int index, int depth, int bound,
            int target,
            std::vector<int>& collect,
            std::vector<std::vector<int>>& ans) {

        if (target == 0) {
            ans.push_back(collect);
            return;
        }

        for (int i = index ; i < bound ; ++i) {

            if (i > index && cands[i] == cands[i - 1]) {
                continue;
            }

            if (cands[i] > target) {
                break;
            }

            collect.push_back(cands[i]);
            runBackTracking(
                cands, i, depth + 1, bound, target - cands[i], collect, ans);
            collect.pop_back();
        }
    }
};