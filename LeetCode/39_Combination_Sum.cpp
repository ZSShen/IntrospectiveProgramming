class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        std::vector<std::vector<int>> ans;
        std::vector<int> collect;

        scanElements(candidates, 0, target, ans, collect);
        return std::move(ans);
    }

private:
    void scanElements(std::vector<int>& candidates, int index, int target,
        std::vector<std::vector<int>>& ans, std::vector<int>& collect) {

        for (int i = index ; i < candidates.size() ; ++i) {
            int current = candidates[i];
            if (current > target) {
                return;
            }

            collect.push_back(current);
            if (current == target) {
                ans.push_back(collect);
                collect.pop_back();
                return;
            }

            scanElements(candidates, i, target - current, ans, collect);
            collect.pop_back();
        }
    }
};