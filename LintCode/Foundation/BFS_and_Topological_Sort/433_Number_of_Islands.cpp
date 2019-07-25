

struct Record {
    int r;
    int c;

    Record(int r, int c)
      : r(r), c(c)
    { }
};


class Solution {
public:
    Solution()
      : directs({{1, 0}, {-1, 0}, {0, 1}, {0, -1}})
    { }

    /**
     * @param grid: a boolean 2D matrix
     * @return: an integer
     */
    int numIslands(vector<vector<bool>> &grid) {
        // write your code here

        int num_r = grid.size();
        if (num_r == 0) {
            return 0;
        }

        int num_c = grid[0].size();
        if (num_c == 0) {
            return 0;
        }

        int count = 0;

        for (int r = 0 ; r < num_r ; ++r) {
            for (int c = 0 ; c < num_c ; ++c) {
                if (grid[r][c]) {
                    grid[r][c] = false;
                    floodAndFill(grid, r, c, num_r, num_c);
                    ++count;
                }
            }
        }

        return count;
    }

private:
    void floodAndFill(auto& grid, int r, int c, int num_r, int num_c) {

        std::queue<Record> queue;
        queue.push(Record(r, c));

        while (!queue.empty()) {
            auto rec = queue.front();
            queue.pop();

            for (const auto& direct : directs) {
                int nr = rec.r + direct[0];
                int nc = rec.c + direct[1];

                if (!(nr >= 0 && nc >= 0 && nr < num_r && nc < num_c) ||
                    !grid[nr][nc]) {
                    continue;
                }

                queue.push(Record(nr, nc));
                grid[nr][nc] = false;
            }
        }
    }

    std::vector<std::vector<int>> directs;
};