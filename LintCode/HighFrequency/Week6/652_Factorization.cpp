class Solution {
public:
    /**
     * @param n: An integer
     * @return: a list of combination
     */
    vector<vector<int>> getFactors(int n) {
        // write your code here

        /**
         *  8
         *  -> 2 4
         *  -> 2 2 2
         */

        std::vector<int> config;
        std::vector<std::vector<int>> ans;

        runBacktracking(2, n, config, ans);

        return ans;
    }

private:
    void runBacktracking(
            int bgn,
            int n,
            std::vector<int>& config,
            std::vector<std::vector<int>>& ans) {

        if (n == 1) {
            if (config.size() > 1) {
                ans.push_back(config);
            }
            return;
        }

        int divisor = bgn;
        while (true) {
            auto res = std::div(n, divisor);

            if (res.quot < divisor) {
                break;
            }

            if (res.rem != 0) {
                ++divisor;
                continue;
            }

            config.push_back(divisor);
            runBacktracking(divisor, res.quot, config, ans);
            config.pop_back();

            ++divisor;
        }

        // To compensate the dividends, such as 4.
        config.push_back(n);
        runBacktracking(n, 1, config, ans);
        config.pop_back();
    }
};