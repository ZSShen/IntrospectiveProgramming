struct Record {

    Record(int row, int col, int depth)
        : row(row), col(col), depth(depth)
    { }

    int row;
    int col;
    int depth;
};


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int num_row = grid.size();
        if (num_row == 0) {
            return -1;
        }

        int num_col = grid[0].size();
        if (num_col == 0) {
            return -1;
        }

        std::queue<Record> queue;
        bool visit[num_row][num_col];

        for (int i = 0 ; i < num_row ; ++i) {
            for (int j = 0 ; j < num_col ; ++j) {
                if (grid[i][j] == 2) {
                    queue.push(Record(i, j, 0));
                    visit[i][j] = true;
                } else {
                    visit[i][j] = false;
                }
            }
        }

        int max_depth = 0;

        while (!queue.empty()) {
            auto front = queue.front();
            queue.pop();

            int r = front.row;
            int c = front.col;
            int depth = front.depth;
            if (depth > max_depth) {
                max_depth = depth;
            }

            if (r > 0 && !visit[r - 1][c] && grid[r - 1][c] == 1) {
                visit[r - 1][c] = true;
                queue.push(Record(r - 1, c, depth + 1));
            }
            if (r < num_row - 1 && !visit[r + 1][c] && grid[r + 1][c] == 1) {
                visit[r + 1][c] = true;
                queue.push(Record(r + 1, c, depth + 1));
            }
            if (c > 0 && !visit[r][c - 1] && grid[r][c - 1] == 1) {
                visit[r][c - 1] = true;
                queue.push(Record(r, c - 1, depth + 1));
            }
            if (c < num_col - 1 && !visit[r][c + 1] && grid[r][c + 1] == 1) {
                visit[r][c + 1] = true;
                queue.push(Record(r, c + 1, depth + 1));
            }
        }

        for (int i = 0 ; i < num_row ; ++i) {
            for (int j = 0 ; j < num_col ; ++j) {
                if (grid[i][j] == 1 && !visit[i][j]) {
                    return -1;
                }
            }
        }

        return max_depth;
    }
};