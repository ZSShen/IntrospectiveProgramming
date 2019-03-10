class Solution {
public:
    /*
     * @param s: A string
     * @return: A list of lists of string
     */
    vector<vector<string>> partition(string &s) {
        // write your code here

        std::vector<std::vector<std::string>> ans;
        int n = s.length();
        if (n == 0) {
            return ans;
        }

        std::vector<std::vector<bool>> dp(n, std::vector<bool>(n, false));
        for (int i = 0 ; i < n ; ++i) {
            dp[i][i] = true;
        }
        for (int i = 0 ; i < n - 1 ; ++i) {
            dp[i][i + 1] = (s[i] == s[i + 1]) ? true : false;
        }
        for (int l = 2 ; l < n ; ++l) {
            for (int i = 0, j = i + l ; i < n - l ; ++i, ++j) {
                dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];
            }
        }

        std::vector<std::string> collect;
        runBacktracking(0, n, s, dp, collect, ans);
        return ans;
    }

private:
    void runBacktracking(
            int end,
            int bound,
            const std::string& str,
            std::vector<std::vector<bool>>& dp,
            std::vector<std::string>& collect,
            std::vector<std::vector<std::string>>& ans) {

        if (end == bound) {
            ans.push_back(collect);
        }

        int bgn = end;
        for (int i = end ; i < bound ; ++i) {
            if (dp[bgn][i]) {
                collect.push_back(str.substr(bgn, i - bgn + 1));
                runBacktracking(i + 1, bound, str, dp , collect, ans);
                collect.pop_back();
            }
        }
    }
};