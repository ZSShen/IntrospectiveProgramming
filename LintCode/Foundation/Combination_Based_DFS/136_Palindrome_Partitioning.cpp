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


class Solution {
public:
    /*
     * @param s: A string
     * @return: A list of lists of string
     */
    vector<vector<string>> partition(string &s) {
        // write your code here

        int n = s.length();
        if (n == 0) {
            return {};
        }

        std::vector<std::string> collect;
        std::vector<std::vector<std::string>> ans;

        // Cache the substring str(i, j). If the substring is palindromic, we
        // cache its content. Otherwise, we cache a empty token.
        std::unordered_map<int, std::unordered_map<int, std::string>> memo;

        runBackTracking(s, 0, n, collect, ans, memo);

        return ans;
    }

private:
    void runBackTracking(
        const std::string& str,
        int index, int bound,
        std::vector<std::string>& collect,
        std::vector<std::vector<std::string>>& ans,
        std::unordered_map<int, std::unordered_map<int, std::string>>& memo) {

        if (index == bound) {
            ans.push_back(collect);
            return;
        }

        for (int i = index ; i < bound ; ++i) {

            std::string token;

            // Hit a cached record.
            if (memo.count(index) == 1 && memo[index].count(i) == 1) {
                token = memo[index][i];
                if (token.empty()) {
                    continue;
                }
            } else {
                token = str.substr(index, i - index + 1);
                if (!isPalindromic(token)) {
                    memo[index][i] = "";
                    continue;
                }
                memo[index][i] = token;
            }

            collect.push_back(token);
            runBackTracking(str, i + 1, bound, collect, ans, memo);
            collect.pop_back();
        }
    }

    bool isPalindromic(const std::string& str) {

        int len = str.length();
        int l = 0, r = len - 1;

        while (l < r) {
            if (str[l] != str[r]) {
                return false;
            }
            ++l;
            --r;
        }

        return true;
    }
};
