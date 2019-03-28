class Solution {
public:
    /*
     * @param n: The number of queens
     * @return: All distinct solutions
     */
    vector<vector<string>> solveNQueens(int n) {
        // write your code here

        std::vector<std::vector<std::string>> ans;
        if (n == 0) {
            return ans;
        }

        std::vector<int> queens(n, 0);
        runBacktracking(0, n, queens, ans);
        return ans;
    }

private:
    void runBacktracking(
            int c,
            int n,
            std::vector<int>& queens,
            std::vector<std::vector<std::string>>& ans) {

        if (c == n) {
            std::string init;
            for (int i = 0 ; i < n ; ++i) {
                init.push_back('.');
            }

            std::vector<std::string> config(n, init);

            for (int i = 0 ; i < n ; ++i) {
                config[queens[i]][i] = 'Q';
            }

            ans.push_back(std::move(config));
            return;
        }

        for (int r = 0 ; r < n ; ++r) {

            bool legal = true;
            for (int i = 0 ; i < c ; ++i) {
                if (queens[i] == r) {
                    legal = false;
                    break;
                }
                if (queens[i] - i == r - c) {
                    legal = false;
                    break;
                }
                if (queens[i] + i == r + c) {
                    legal = false;
                    break;
                }
            }

            if (legal) {
                queens[c] = r;
                runBacktracking(c + 1, n, queens, ans);
            }
        }
    }
};