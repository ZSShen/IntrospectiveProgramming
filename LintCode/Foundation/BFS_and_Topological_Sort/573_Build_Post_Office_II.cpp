

struct Record {
    int x, y;

    Record(int x, int y)
      : x(x), y(y)
    { }
};


class Solution {
public:
    Solution()
      : directs({{1, 0}, {-1, 0}, {0, 1}, {0, -1}})
    { }

    /**
     * @param grid: a 2D grid
     * @return: An integer
     */
    int shortestDistance(vector<vector<int>> &grid) {
        // write your code here

        int num_r = grid.size();
        if (num_r == 0) {
            return 0;
        }

        int num_c = grid[0].size();
        if (num_c == 0) {
            return 0;
        }

        // Collect the houses.
        std::vector<Record> recs;
        int num_house = 0;
        for (int i = 0 ; i < num_r ; ++i) {
            for (int j = 0 ; j < num_c ; ++j) {
                if (grid[i][j] == 1) {
                    recs.push_back(Record(i, j));
                    ++num_house;
                }
            }
        }

        std::vector<std::vector<int>> dist(num_r, std::vector<int>(num_c, 0));
        std::vector<std::vector<int>> reach(num_r, std::vector<int>(num_c, 0));

        for (const auto& rec : recs) {
            floodAndFill(rec.x, rec.y, num_r, num_c, grid, dist, reach);
        }

        int ans = INT_MAX;
        for (int i = 0 ; i < num_r ; ++i) {
            for (int j = 0 ; j < num_c ; ++j) {
                if (reach[i][j] == num_house) {
                    ans = std::min(ans, dist[i][j]);
                }
            }
        }

        return (ans != INT_MAX) ? ans : -1;
    }

private:
    void floodAndFill(
            int r, int c, int num_r, int num_c,
            const auto& grid, auto& dist, auto& reach) {

        std::queue<Record> queue;
        queue.push(Record(r, c));

        std::vector<std::vector<bool>>
            visit(num_r, std::vector<bool>(num_c, false));
        visit[r][c] = true;

        int level = 0;

        while (!queue.empty()) {
            int n = queue.size();
            ++level;

            for (int i = 0 ; i < n ; ++i) {
                auto rec = queue.front();
                queue.pop();

                int x = rec.x;
                int y = rec.y;

                for (const auto& direct : directs) {
                    int nx = x + direct[0];
                    int ny = y + direct[1];

                    if (!(nx >= 0 && ny >= 0 && nx < num_r && ny < num_c) ||
                        visit[nx][ny] ||
                        grid[nx][ny] != 0) {
                        continue;
                    }

                    // Reach an empty cell.
                    visit[nx][ny] = true;
                    queue.push(Record(nx, ny));

                    dist[nx][ny] += level;
                    ++reach[nx][ny];
                }
            }
        }
    }

    std::vector<std::vector<int>> directs;
};