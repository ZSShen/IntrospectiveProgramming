class Solution {
public:
    /**
     * @param grid: Given a 2D grid, each cell is either 'W', 'E' or '0'
     * @return: an integer, the maximum enemies you can kill using one bomb
     */
    int maxKilledEnemies(vector<vector<char>> &grid) {
        // write your code here

        int num_r = grid.size();
        if (num_r == 0) {
            return 0;
        }

        int num_c = grid[0].size();
        if (num_c == 0) {
            return 0;
        }

        std::vector<std::vector<int>> left(num_r, std::vector<int>(num_c, 0));
        std::vector<std::vector<int>> right(num_r, std::vector<int>(num_c, 0));
        std::vector<std::vector<int>> up(num_r, std::vector<int>(num_c, 0));
        std::vector<std::vector<int>> down(num_r, std::vector<int>(num_c, 0));

        // O(mn) for filling left and right.
        for (int i = 0 ; i < num_r ; ++i) {

            if (grid[i][0] == 'E') {
                left[i][0] = 1;
            }
            if (grid[i][num_c - 1] == 'E') {
                right[i][num_c - 1] = 1;
            }

            for (int j = 1, k = num_c - 2 ; j < num_c ; ++j, --k) {
                if (grid[i][j] != 'W') {
                    left[i][j] = left[i][j - 1] + (grid[i][j] == 'E');
                }
                if (grid[i][k] != 'W') {
                    right[i][k] = right[i][k + 1] + (grid[i][k] == 'E');
                }
            }
        }

        // O(nm) for filling up and down.
        for (int i = 0 ; i < num_c ; ++i) {

            if (grid[0][i] == 'E') {
                up[0][i] = 1;
            }
            if (grid[num_r - 1][i] == 'E') {
                down[num_r - 1][i] = 1;
            }

            for (int j = 1, k = num_r - 2 ; j < num_r ; ++j, --k) {
                if (grid[j][i] != 'W') {
                    up[j][i] = up[j - 1][i] + (grid[j][i] == 'E');
                }
                if (grid[k][i] != 'W') {
                    down[k][i] = down[k + 1][i] + (grid[k][i] == 'E');
                }
            }
        }

        int ans = 0;
        for (int i = 0 ; i < num_r ; ++i) {
            for (int j = 0 ; j < num_c ; ++j) {
                if (grid[i][j] == '0') {
                    ans = std::max(ans, up[i][j] + down[i][j] + left[i][j] + right[i][j]);
                }
            }
        }

        return ans;
    }
};