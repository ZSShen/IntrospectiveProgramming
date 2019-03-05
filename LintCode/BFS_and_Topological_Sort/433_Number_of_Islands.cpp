class Solution {
public:
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

        std::vector<std::vector<bool>> visit(
            num_r, std::vector<bool>(num_c, false));

        int count = 0;
        for (int i = 0 ; i < num_r ; ++i) {
            for (int j = 0 ; j < num_c ; ++j) {
                if (grid[i][j] && !visit[i][j]) {
                    runBfs(num_r, num_c, i, j, grid, visit);
                    ++count;
                }
            }
        }

        return count;
    }

private:
    void runBfs(int num_r, int num_c, int r, int c,
                std::vector<std::vector<bool>>& grid,
                std::vector<std::vector<bool>>& visit) {

        std::queue<std::pair<int, int>> queue;
        visit[r][c] = true;
        queue.push(std::make_pair(r, c));

        while (!queue.empty()) {
            auto pair = queue.front();
            queue.pop();

            r = pair.first;
            c = pair.second;

            if (r >= 1 && grid[r - 1][c] && !visit[r - 1][c]) {
                visit[r - 1][c] = true;
                queue.push(std::make_pair(r - 1, c));
            }
            if (r < num_r - 1 && grid[r + 1][c] && !visit[r + 1][c]) {
                visit[r + 1][c] = true;
                queue.push(std::make_pair(r + 1, c));
            }
            if (c >= 1 && grid[r][c - 1] && !visit[r][c - 1]) {
                visit[r][c - 1] = true;
                queue.push(std::make_pair(r, c - 1));
            }
            if (c < num_c - 1 && grid[r][c + 1] && !visit[r][c + 1]) {
                visit[r][c + 1] = true;
                queue.push(std::make_pair(r, c + 1));
            }
        }
    }
};