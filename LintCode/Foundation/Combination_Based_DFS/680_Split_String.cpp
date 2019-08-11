class Solution {
public:
    /*
     * @param : a string to be split
     * @return: all possible split string array
     */
    vector<vector<string>> splitString(string& s) {
        // write your code here

        int n = s.length();
        if (n == 0) {
            return {{}};
        }

        std::vector<std::string> collect;
        std::vector<std::vector<std::string>> ans;
        runBackTracking(s, 0, n, collect, ans);

        return ans;
    }

private:
    void runBackTracking(
            const std::string& str,
            int index, int bound,
            std::vector<std::string>& collect,
            std::vector<std::vector<std::string>>& ans) {

        if (index == bound) {
            ans.push_back(collect);
            return;
        }

        auto token = str.substr(index, 1);
        collect.push_back(token);
        runBackTracking(str, index + 1, bound, collect, ans);
        collect.pop_back();

        if (index + 1 < bound) {
            token = str.substr(index, 2);
            collect.push_back(token);
            runBackTracking(str, index + 2, bound, collect, ans);
            collect.pop_back();
        }
    }
};