class Solution {
public:
    /**
     * @param board: the board
     * @return: whether the Sudoku is valid
     */
    bool isValidSudoku(vector<vector<char>> &board) {
        // write your code here

        for (int i = 0 ; i < 3 ; ++i) {
            for (int j = 0 ; j < 3 ; ++j) {
                int k = i * 3 + j;

                bool valid = isValidRow(board, k, 9);
                if (!valid) {
                    return false;
                }
                valid = isValidColumn(board, 9, k);
                if (!valid) {
                    return false;
                }

                int lr = i * 3;
                int lc = j * 3;
                int rr = lr + 3;
                int rc = lc + 3;
                valid = isValidSubmatrix(board, lr, lc, rr, rc);
                if (!valid)  {
                    return false;
                }
            }
        }

        return true;
    }

private:
    bool isValidCell(
        char ch, std::vector<bool>& use) {

        if (ch == '.') {
            return true;
        }

        int idx = ch - '0';
        if (use[idx]) {
            return false;
        }

        use[idx] = true;
        return true;
    }

    bool isValidRow(
        const std::vector<std::vector<char>>& board, int r, int num_c) {

        std::vector<bool> use(10, false);

        for (int i = 0 ; i < num_c ; ++i) {
            char ch = board[r][i];
            if (!isValidCell(ch, use)) {
                return false;
            }
        }

        return true;
    }

    bool isValidColumn(
        const std::vector<std::vector<char>>& board, int num_r, int c) {

        std::vector<bool> use(10, false);

        for (int i = 0 ; i < num_r ; ++i) {
            char ch = board[i][c];
            if (!isValidCell(ch, use)) {
                return false;
            }
        }

        return true;
    }

    bool isValidSubmatrix(
        const std::vector<std::vector<char>>& board,
        int lr, int lc, int rr, int rc) {

        std::vector<bool> use(10, false);

        for (int i = lr ; i < rr ; ++i) {
            for (int j = lc ; j < rc ; ++j) {
                char ch = board[i][j];
                if (!isValidCell(ch, use)) {
                    return false;
                }
            }
        }

        return true;
    }
};


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        std::vector<std::vector<bool>> row(9, std::vector<bool>(9, false));
        std::vector<std::vector<bool>> col(9, std::vector<bool>(9, false));
        std::vector<std::vector<bool>> mtx(9, std::vector<bool>(9, false));

        for (int r = 0 ; r < 9 ; ++r) {
            for (int c = 0 ; c < 9 ; ++c) {
                int num = board[r][c];

                if (num == '.') {
                    continue;
                }
                num -= '1';

                if (row[r][num] == false) {
                    row[r][num] = true;
                } else {
                    return false;
                }

                if (col[c][num] == false) {
                    col[c][num] = true;
                } else {
                    return false;
                }

                int index = getIndex(r, c);
                if (mtx[index][num] == false) {
                    mtx[index][num] = true;
                } else {
                    return false;
                }
            }
        }

        return true;
    }

private:
    int getIndex(int r, int c) {
        return (r / 3) * 3 + c / 3;
    }
};