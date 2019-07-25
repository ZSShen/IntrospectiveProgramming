

struct Record {
    int x;
    int y;

    Record(int x, int y)
      : x(x), y(y)
    { }
};


class Solution {
public:
    Solution()
      : directs({{1, 0}, {-1, 0}, {0, 1}, {0, -1}})
    { }

    /*
     * @param board: board a 2D board containing 'X' and 'O'
     * @return: nothing
     */
    void surroundedRegions(vector<vector<char>> &board) {
        // write your code here

        /**
         *  X X X X      X X X X      X X X X
         *  X O O X  =>  X O O X  =>  X X X X
         *  X X O X      X X O X      X X X X
         *  X O X X      X B X X      X O X X
         *
         *  X X X X      X X X X      X X X X
         *  X O O X  =>  X B B X  =>  X O O X
         *  X O O X      X B B X      X O O X
         *  X O X X      X B X X      X O X X
         */

        int num_r = board.size();
        if (num_r == 0) {
            return;
        }

        int num_c = board[0].size();
        if (num_c == 0) {
            return;
        }

        std::vector<std::vector<bool>>
            visit(num_r, std::vector<bool>(num_c, false));

        for (int i = 0 ; i < num_r ; ++i) {
            if (board[i][0] == 'O') {
                floodAndFill(board, visit, i, 0, num_r, num_c);
            }
            if (board[i][num_c - 1] == 'O') {
                floodAndFill(board, visit, i, num_c - 1, num_r, num_c);
            }
        }

        for (int i = 1 ; i < num_c - 1 ; ++i) {
            if (board[0][i] == 'O') {
                floodAndFill(board, visit, 0, i, num_r, num_c);
            }
            if (board[num_r - 1][i] == 'O') {
                floodAndFill(board, visit, num_r - 1, i, num_r, num_c);
            }
        }

        for (int i = 0 ; i < num_r ; ++i) {
            for (int j = 0 ; j < num_c ; ++j) {
                if (board[i][j] == 'B') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }

private:
    void floodAndFill(
            auto& board, auto& visit, int r, int c, int num_r, int num_c) {

        board[r][c] = 'B';
        visit[r][c] = true;

        std::queue<Record> queue;
        queue.push(Record(r, c));

        while (!queue.empty()) {
            auto rec = queue.front();
            queue.pop();
            int x = rec.x;
            int y = rec.y;

            for (const auto& direct : directs) {
                int nx = x + direct[0];
                int ny = y + direct[1];

                if (!(nx >=0 && ny >=0 && nx < num_r && ny < num_c) ||
                    board[nx][ny] != 'O' ||
                    visit[nx][ny]) {
                    continue;
                }

                board[nx][ny] = 'B';
                visit[nx][ny] = true;
                queue.push(Record(nx, ny));
            }
        }
    }


    std::vector<std::vector<int>> directs;
};