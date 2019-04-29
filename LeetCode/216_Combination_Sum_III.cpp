class Solution {
    
public:
    Solution()
      : cands({1,2,3,4,5,6,7,8,9})
     { }    
    
    vector<vector<int>> combinationSum3(int k, int n) {
        
        std::vector<int> select;
        std::vector<std::vector<int>> ans;
        
        runBacktracking(0, 9, n, 0, k, select, ans);
        return ans;
    }
    
private:
    void runBacktracking(
            int bgn,
            int end,
            int target,
            int count,
            int k,
            std::vector<int>& select,
            std::vector<std::vector<int>>& ans) {
        
        if (target == 0 && count == k) {
            ans.push_back(select);
            return;
        }
        
        for (int i = bgn ; i < end ; ++i) {
            if (cands[i] > target) {
                break;
            }
            
            select.push_back(cands[i]);
            runBacktracking(
                i + 1, end, target - cands[i], count + 1, k, select, ans);
            select.pop_back();
        }
    }
    
    std::vector<int> cands;
};