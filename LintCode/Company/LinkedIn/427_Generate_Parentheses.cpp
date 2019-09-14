class Solution {
public:
    /**
     * @param n: n pairs
     * @return: All combinations of well-formed parentheses
     */
    vector<string> generateParenthesis(int n) {
        // write your code here

        std::string config;
        std::vector<std::string> ans;
        runBackTracking(n, 0, 0, config, ans);

        return ans;
    }

private:
    void runBackTracking(
        int n, int count_left, int count_right, auto& config, auto& ans) {

        if (n == count_left && n == count_right) {
            ans.push_back(config);
            return;
        }

        if (count_left == count_right) {
            config.push_back('(');
            runBackTracking(n, count_left + 1, count_right, config, ans);
            config.pop_back();
            return;
        }

        if (count_left < n) {
            config.push_back('(');
            runBackTracking(n, count_left + 1, count_right, config, ans);
            config.pop_back();
        }

        config.push_back(')');
        runBackTracking(n, count_left, count_right + 1, config, ans);
        config.pop_back();
    }
};