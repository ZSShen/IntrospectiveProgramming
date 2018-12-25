class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        int dim_row = grid.size();
        if (dim_row == 0) {
            return 0;
        }
        int dim_col = grid[0].size();

        int count = 0;
        for (int i = 0 ; i < dim_row ; ++i) {
            for (int j = 0 ; j < dim_col ; ++j) {
                if (grid[i][j] == '1') {
                    ++count;
                    runDFS(dim_row, dim_col, i, j, grid);
                }
            }
        }

        return count;
    }

    void runDFS(int dim_row,
                int dim_col,
                int bgn_row,
                int bgn_col,
                std::vector<std::vector<char>>& grid) {

        grid[bgn_row][bgn_col] = '0';

        if (bgn_row > 0 &&
            grid[bgn_row - 1][bgn_col] == '1') {
            runDFS(dim_row, dim_col, bgn_row - 1, bgn_col, grid);
        }
        if (bgn_row < dim_row - 1 &&
            grid[bgn_row + 1][bgn_col] == '1') {
            runDFS(dim_row, dim_col, bgn_row + 1, bgn_col, grid);
        }
        if (bgn_col > 0 &&
            grid[bgn_row][bgn_col - 1] == '1') {
            runDFS(dim_row, dim_col, bgn_row, bgn_col - 1, grid);
        }
        if (bgn_col < dim_col - 1 &&
            grid[bgn_row][bgn_col + 1] == '1') {
            runDFS(dim_row, dim_col, bgn_row, bgn_col + 1, grid);
        }
    }
};

