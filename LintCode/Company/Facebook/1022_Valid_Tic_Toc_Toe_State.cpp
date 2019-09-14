class Solution {
public:
    /**
     * @param board: the given board
     * @return: True if and only if it is possible to reach this board position during the course of a valid tic-tac-toe game
     */
    bool validTicTacToe(vector<string> &board) {
        // Write your code

        int count_o = count(board, 'O');
        int count_x = count(board, 'X');
        bool win_o = win(board, 'O');
        bool win_x = win(board, 'X');

        if (win_o && win_x) {
            return false;
        }

        if (win_x) {
            return count_x == count_o + 1;
        }
        if (win_o) {
            return count_o == count_x ;
        }

        return count_x == count_o || count_x == count_o + 1;
    }

private:
    int count(const auto& board, char target) {
        int count = 0;

        for (const auto& line : board) {
            for (char ch : line) {
                if (ch == target) {
                    ++count;
                }
            }
        }

        return count;
    }

    bool win(const auto& board, char target) {

        for (int i = 0 ; i < 3 ; ++i) {
            // Check the rows.
            if (board[i][0] == target &&
                board[i][1] == target &&
                board[i][2] == target) {
                return true;
            }

            // Check the columns.
            if (board[0][i] == target &&
                board[1][i] == target &&
                board[2][i] == target) {
                return true;
            }
        }

        // Check the 2 diagonals.
        return (board[0][0] == target &&
                board[1][1] == target &&
                board[2][2] == target) ||
               (board[0][2] == target &&
                board[1][1] == target &&
                board[2][0] == target);
    }
};