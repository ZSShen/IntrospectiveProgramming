class Solution {
public:
    /**
     * @param grid: a list of lists of integers
     * @return: An integer, minimizes the sum of all numbers along its path
     */
    int minPathSum(vector<vector<int>> &grid) {
        // write your code here

        /**
         * dp[i][j]: The minimum path sum which ends at cell (i, j).
         *
         * dp[i][j] = Min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j]
         */

        int num_r = grid.size();
        if (num_r == 0) {
            return 0;
        }

        int num_c = grid[0].size();
        if (num_c == 0) {
            return 0;
        }

        int dp[num_r][num_c] = {{0}};
        dp[0][0] = grid[0][0];

        for (int i = 1 ; i < num_r ; ++i) {
            dp[i][0] = grid[i][0] + dp[i - 1][0];
        }
        for (int i = 1 ; i < num_c ; ++i) {
            dp[0][i] = grid[0][i] + dp[0][i - 1];
        }

        for (int i = 1 ; i < num_r ; ++i) {
            for (int j = 1 ; j < num_c ; ++j) {
                dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }

        return dp[num_r - 1][num_c - 1];
    }
};