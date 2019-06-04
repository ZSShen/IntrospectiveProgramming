class Solution {
public:
    /**
     * @param board: the sudoku puzzle
     * @return: nothing
     */
    void solveSudoku(vector<vector<int>> &board) {
        // write your code here

        std::vector<std::vector<bool>> use_rows(9, std::vector<bool>(9, false));
        std::vector<std::vector<bool>> use_cols(9, std::vector<bool>(9, false));
        std::vector<std::vector<bool>> use_grids(9, std::vector<bool>(9, false));

        for (int i = 0 ; i < 9 ; ++i) {
            for (int j = 0 ; j < 9 ; ++j) {

                if (board[i][j] == 0) {
                    continue;
                }
                int index = board[i][j] - 1;

                use_rows[i][index] = true;
                use_cols[j][index] = true;
                use_grids[getSubGridIndex(i, j)][index] = true;
            }
        }

        runBacktracking(0, 81, board, use_rows, use_cols, use_grids);
    }


private:
    int getSubGridIndex(int r, int c) {

        int ir = r / 3;
        int ic = c / 3;
        return ir * 3 + ic;
    }


    bool runBacktracking(
            int count,
            int bound,
            std::vector<std::vector<int>>& board,
            std::vector<std::vector<bool>>& use_rows,
            std::vector<std::vector<bool>>& use_cols,
            std::vector<std::vector<bool>>& use_grids) {

        if (count == bound) {
            return true;
        }

        int x = count / 9;
        int y = count % 9;

        if (board[x][y] != 0) {
            return runBacktracking(
                count + 1, bound, board, use_rows, use_cols, use_grids);
        }

        for (int i = 0 ; i < 9 ; ++i) {

            int idx = getSubGridIndex(x, y);
            if (use_rows[x][i] || use_cols[y][i] || use_grids[idx][i]) {
                continue;
            }

            board[x][y] = i + 1;
            use_rows[x][i] = true;
            use_cols[y][i] = true;
            use_grids[idx][i] = true;

            bool res = runBacktracking(
                count + 1, bound, board, use_rows, use_cols, use_grids);
            if (res) {
                return true;
            }

            board[x][y] = 0;
            use_rows[x][i] = false;
            use_cols[y][i] = false;
            use_grids[idx][i] = false;
        }

        return false;
    }
};