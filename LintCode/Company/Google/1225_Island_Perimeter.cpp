class Solution {
public:
    Solution()
      : directs({{1, 0}, {-1, 0}, {0, 1}, {0, -1}})
    { }

    /**
     * @param grid: a 2D array
     * @return: the perimeter of the island
     */
    int islandPerimeter(vector<vector<int>> &grid) {
        // Write your code here

        int num_r = grid.size();
        if (num_r == 0) {
            return 0;
        }
        int num_c = grid[0].size();
        if (num_c == 0) {
            return 0;
        }

        int sum = 0;
        for (int x = 0 ; x < num_r ; ++x) {
            for (int y = 0 ; y < num_c ; ++y) {

                if (grid[x][y] == 0) {
                    continue;
                }

                for (const auto& direct : directs) {
                    int nx = x + direct[0];
                    int ny = y + direct[1];
                    if (connectToWater(grid, num_r, num_c, nx, ny)) {
                        ++sum;
                    }
                }
            }
        }

        return sum;
    }

private:
    bool connectToWater(const auto& grid, int num_r, int num_c, int x, int y) {
        if (x >= 0 && y >= 0 && x < num_r && y < num_c) {
            return grid[x][y] == 0;
        }
        return true;
    }

    std::vector<std::vector<int>> directs;
};