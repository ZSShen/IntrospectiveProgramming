class Solution {
public:
    /**
     * @param str: A string
     * @return: all permutations
     */
    vector<string> stringPermutation2(string &str) {
        // write your code here
        
        int len = str.length();
        if (len == 0) {
            return {""};
        }
        
        std::sort(str.begin(), str.end());
        
        std::vector<bool> visit(len, false);
        std::string conf;
        std::vector<std::string> ans;
        runBacktracking(0, len, str, visit, conf, ans);
        
        return ans;
    }

private:
    void runBacktracking(
            int idx,
            int bnd,
            const std::string& str,
            std::vector<bool>& visit,
            std::string& conf,
            std::vector<std::string>& ans) {
        
        if (idx == bnd) {
            ans.push_back(conf);
            return;
        }
        
        for (int i = 0 ; i < bnd ; ++i) {
            if (visit[i]) {
                continue;
            }
            
            if (i > 0 && str[i] == str[i - 1] && !visit[i - 1]) {
                continue;
            }
            
            visit[i] = true;
            conf.push_back(str[i]);
            runBacktracking(idx + 1, bnd, str, visit, conf, ans);
            visit[i] = false;
            conf.pop_back();
        }
    }
};