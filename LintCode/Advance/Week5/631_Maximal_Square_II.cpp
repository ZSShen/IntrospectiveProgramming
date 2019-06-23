class Solution {
public:
    /**
     * @param matrix: a matrix of 0 an 1
     * @return: an integer
     */
    int maxSquare2(vector<vector<int>> &matrix) {
        // write your code here

        /**
         *  1 0 1 0 0
         *  1 0 0 1 0
         *  1 1 0 0 1
         *  1 0 0 1 0
         *
         *  dp[i][j]: The length of the largest square that fulfills the
         *            requirement.
         *
         *  row[i][j]: The number of consecutive 0s spanning from the position
         *             (i, j) to the left boundary on the ith row.
         *
         *  col[i][j]: The number of consecutive 0s spanning from the position
         *             (i, j) to the upper boundary on the jth column.
         *
         *  dp[i][j] = MIN {dp[i - 1][j - 1], row[i][j - 1], col[i - 1][j]} + 1
         */

        int num_r = matrix.size();
        if (num_r == 0) {
            return 0;
        }

        int num_c = matrix[0].size();
        if (num_c == 0) {
            return 0;
        }

        std::vector<std::vector<int>> dp(num_r, std::vector<int>(num_c, 0));
        std::vector<std::vector<int>> row(num_r, std::vector<int>(num_c, 0));
        std::vector<std::vector<int>> col(num_r, std::vector<int>(num_c, 0));

        int ans;
        if (matrix[0][0] == 0) {
            row[0][0] = 1;
            col[0][0] = 1;
            ans = 0;
        } else {
            dp[0][0] = 1;
            ans = 1;
        }

        for (int i = 1 ; i < num_r ; ++i) {
            if (matrix[i][0] == 1) {
                dp[i][0] = 1;
                ans = 1;
            } else {
                col[i][0] = col[i - 1][0] + 1;
                row[i][0] = 1;
            }
        }

        for (int i = 1 ; i < num_c ; ++i) {
            if (matrix[0][i] == 1) {
                dp[0][i] = 1;
                ans = 1;
            } else {
                row[0][i] = row[0][i - 1] + 1;
                col[0][i] = 1;
            }
        }

        for (int i = 1 ; i < num_r ; ++i) {
            for (int j = 1 ; j < num_c ; ++j) {

                if (matrix[i][j] == 0) {
                    row[i][j] = row[i][j - 1] + 1;
                    col[i][j] = col[i - 1][j] + 1;
                    continue;
                }

                dp[i][j] = std::min(
                    std::min(row[i][j - 1], col[i - 1][j]),
                    dp[i - 1][j - 1]) + 1;

                ans = std::max(ans, dp[i][j]);
            }
        }

        return ans * ans;
    }
};