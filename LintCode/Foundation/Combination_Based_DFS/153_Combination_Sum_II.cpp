class Solution {
public:
    /**
     * @param num: Given the candidate numbers
     * @param target: Given the target number
     * @return: All the combinations that sum to target
     */
    vector<vector<int>> combinationSum2(vector<int> &cands, int target) {
        // write your code here

        int n = cands.size();
        if (n == 0) {
            return {};
        }

        std::sort(cands.begin(), cands.end());

        std::vector<int> collect;
        std::vector<std::vector<int>> ans;
        runBackTracking(cands, 0, n, target, collect, ans);

        return ans;
    }

private:
    void runBackTracking(
            const std::vector<int>& cands,
            int index, int bound,
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
                cands, i + 1, bound, target - cands[i], collect, ans);
            collect.pop_back();
        }
    }
};
