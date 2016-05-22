class Solution
{
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        int count_row = grid.size();
        if (count_row == 0)
            return 0;
        int count_col = grid[0].size();
        if (count_col == 0)
            return 0;

        int dp[count_row][count_col];
        dp[0][0] = grid[0][0];
        for (int i = 1 ; i < count_col ; ++i)
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        for (int i = 1 ; i < count_row ; ++i)
            dp[i][0] = dp[i - 1][0] + grid[i][0];

        for (int i = 1 ; i < count_row ; ++i) {
            for (int j = 1 ; j < count_col ; ++j)
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }

        return dp[count_row - 1][count_col - 1];
    }
};