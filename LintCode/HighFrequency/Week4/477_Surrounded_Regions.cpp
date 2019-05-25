
struct Record {
    int x;
    int y;

    Record(int x, int y)
      : x(x),
        y(y)
    { }
};


class Solution {
public:
    Solution()
      : directs({
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
      })
    { }

    /*
     * @param board: board a 2D board containing 'X' and 'O'
     * @return: nothing
     */
    void surroundedRegions(vector<vector<char>> &board) {
        // write your code here

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

        for (int i = 0 ; i < num_c ; ++i) {
            int x = 0;
            int y = i;

            visit[x][y] = true;
            if (board[x][y] == 'O') {
                floodAndFill(x, y, num_r, num_c, visit, board);
            }

            x = num_r - 1;
            visit[x][y] = true;
            if (board[x][y] == 'O') {
                floodAndFill(x, y, num_r, num_c, visit, board);
            }
        }

        for (int i = 1 ; i < num_r - 1 ; ++i) {
            int x = i;
            int y = 0;

            visit[x][y] = true;
            if (board[x][y] == 'O') {
                floodAndFill(x, y, num_r, num_c, visit, board);

            }

            y = num_c - 1;
            visit[x][y] = true;
            if (board[x][y] == 'O') {
                floodAndFill(x, y, num_r, num_c, visit, board);
            }
        }

        for (int i = 0 ; i < num_r ; ++i) {
            for (int j = 0 ; j < num_c ; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                if (board[i][j] == 'B') {
                    board[i][j] = 'O';
                }
            }
        }
    }


private:
    void floodAndFill(
            int x, int y,
            int num_r, int num_c,
            std::vector<std::vector<bool>>& visit,
            std::vector<std::vector<char>>& board) {

        board[x][y] = 'B';

        std::queue<Record> queue;
        queue.push(Record(x, y));

        while (!queue.empty()) {

            auto front = queue.front();
            queue.pop();
            x = front.x;
            y = front.y;

            for (const auto& direct : directs) {
                int nx = x + direct[0];
                int ny = y + direct[1];

                if (!(nx >= 0 && nx < num_r && ny >= 0 && ny < num_c)) {
                    continue;
                }
                if (visit[nx][ny]) {
                    continue;
                }

                visit[nx][ny] = true;

                if (board[nx][ny] != 'O') {
                    continue;
                }

                board[nx][ny] = 'B';
                queue.push(Record(nx, ny));
            }
        }
    }

    std::vector<std::vector<int>> directs;
};