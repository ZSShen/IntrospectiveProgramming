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
