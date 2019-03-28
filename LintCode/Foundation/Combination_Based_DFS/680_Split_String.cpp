class Solution {
public:
    /*
     * @param : a string to be split
     * @return: all possible split string array
     */
    vector<vector<string>> splitString(string& s) {
        // write your code here

        std::vector<std::vector<std::string>> ans;
        int size = s.length();
        if (size == 0) {
            ans.push_back(std::vector<std::string>());
            return ans;
        }

        std::vector<std::string> collect;
        int index = 0;
        runBacktracking(index, size, s, collect, ans);
        return ans;
    }

private:
    void runBacktracking(
            int end,
            int bound,
            const std::string& str,
            std::vector<std::string>& collect,
            std::vector<std::vector<std::string>>& ans) {

        if (end == bound) {
            ans.push_back(collect);
            return;
        }

        int bgn = end;
        collect.push_back(str.substr(bgn, 1));
        runBacktracking(end + 1, bound, str, collect, ans);
        collect.pop_back();

        if (bgn + 1 < bound) {
            collect.push_back(str.substr(bgn, 2));
            runBacktracking(end + 2, bound, str, collect, ans);
            collect.pop_back();
        }
    }
};