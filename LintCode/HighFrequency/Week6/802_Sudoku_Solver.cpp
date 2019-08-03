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


class Solution {
public:
    /**
     * @param board: the sudoku puzzle
     * @return: nothing
     */
    void solveSudoku(vector<vector<int>> &board) {
        // write your code here

        std::vector<std::vector<int>> rows(9, std::vector<int>(10, false));
        std::vector<std::vector<int>> cols(9, std::vector<int>(10, false));
        std::vector<std::vector<int>> subs(9, std::vector<int>(10, false));

        for (int i = 0 ; i < 9 ; ++i) {
            for (int j = 0 ; j < 9 ; ++j) {
                int num = board[i][j];
                if (num == 0) {
                    continue;
                }

                rows[i][num] = true;
                cols[j][num] = true;
                subs[getSubMatrixIndex(i, j)][num] = true;
            }
        }

        runBackTracking(0, 0, board, rows, cols, subs);
    }

private:
    bool runBackTracking(
        int r, int c,
        std::vector<std::vector<int>>& board,
        std::vector<std::vector<int>>& rows,
        std::vector<std::vector<int>>& cols,
        std::vector<std::vector<int>>& subs) {

        if (c == 9) {
            c = 0;
            ++r;
        }

        if (r == 9 && c == 0) {
            return true;
        }

        int num = board[r][c];

        if (num != 0) {
            return runBackTracking(r, c + 1, board, rows, cols, subs);
        }

        int s = getSubMatrixIndex(r, c);

        for (int i = 1 ; i <= 9 ; ++i) {
            if (rows[r][i] || cols[c][i] || subs[s][i]) {
                continue;
            }

            rows[r][i] = true;
            cols[c][i] = true;
            subs[s][i] = true;
            board[r][c] = i;

            bool res = runBackTracking(r, c + 1, board, rows, cols, subs);
            if (res) {
                return true;
            }

            rows[r][i] = false;
            cols[c][i] = false;
            subs[s][i] = false;
            board[r][c] = 0;
        }

        return false;
    }

    int getSubMatrixIndex(int r, int c) {

        if (r < 3) {
            if (c < 3) {
                return 0;
            } else if (c < 6) {
                return 1;
            } else {
                return 2;
            }
        } else if (r < 6) {
            if (c < 3) {
                return 3;
            } else if (c < 6) {
                return 4;
            } else {
                return 5;
            }
        } else {
            if (c < 3) {
                return 6;
            } else if (c < 6) {
                return 7;
            } else {
                return 8;
            }
        }
    }
};