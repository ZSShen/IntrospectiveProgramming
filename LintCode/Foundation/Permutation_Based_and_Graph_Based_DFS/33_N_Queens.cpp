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

        std::vector<int> queens;
        runBackTracking(0, n, queens, ans);
        return ans;
    }


private:
    void runBackTracking(
            int index, int dim,
            std::vector<int> queens,
            std::vector<std::vector<std::string>>& ans) {

        if (index == dim) {
            std::string row;
            for (int i = 0 ; i < dim ; ++i) {
                row.push_back('.');
            }

            std::vector<std::string> config(dim, row);

            for (int c = 0 ; c < dim ; ++c) {
                int r = queens[c];
                config[r][c] = 'Q';
            }

            ans.emplace_back(std::move(config));
            return;
        }

        for (int nr = 0 ; nr < dim ; ++nr) {
            bool check = true;

            for (int c = 0 ; c < index ; ++c) {
                int r = queens[c];

                // Check the row conflict.
                if (nr == r) {
                    check = false;
                    break;
                }

                // Check the diagonal conflict.
                if (r - c == nr - index) {
                    check = false;
                    break;
                }

                // Check the anti-diagonal conflict.
                if (r + c == nr + index) {
                    check = false;
                    break;
                }
            }

            if (!check) {
                continue;
            }

            queens.push_back(nr);
            runBackTracking(index + 1, dim, queens, ans);
            queens.pop_back();
        }
    }
};