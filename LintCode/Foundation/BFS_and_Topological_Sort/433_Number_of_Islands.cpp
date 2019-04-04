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

        std::vector<std::vector<int>> direct;
        direct.push_back({1, 0});
        direct.push_back({0, 1});
        direct.push_back({-1, 0});
        direct.push_back({0, -1});

        int count = 0;
        for (int i = 0 ; i < num_r ; ++i) {
            for (int j = 0 ; j < num_c ; ++j) {
                if (grid[i][j]) {
                    ++count;
                    runBFS(i, j, num_r, num_c, grid, direct);
                }
            }
        }

        return count;
    }

private:
    void runBFS(
            int r,
            int c,
            int num_r,
            int num_c,
            std::vector<std::vector<bool>>& grid,
            const std::vector<std::vector<int>>& direct) {

        std::queue<std::pair<int, int>> queue;
        queue.push(std::make_pair(r, c));
        grid[r][c] = false;

        while (!queue.empty()) {
            auto pair = queue.front();
            queue.pop();

            r = pair.first;
            c = pair.second;

            for (int i = 0 ; i < 4 ; ++i) {
                int new_r = r + direct[i][0];
                int new_c = c + direct[i][1];

                if (new_r < 0 || new_r == num_r ||
                    new_c < 0 || new_c == num_c) {
                    continue;
                }
                if (grid[new_r][new_c]) {
                    queue.push(std::make_pair(new_r, new_c));
                    grid[new_r][new_c] = false;
                }
            }
        }
    }
};