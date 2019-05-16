class Solution {
public:
    /**
     * @param matrix: a matrix of 0 and 1
     * @return: an integer
     */
    int maxSquare(vector<vector<int>> &matrix) {
        // write your code here

        /**
         *    1 0 1 0 0
         *    1 0 1 1 1
         *    1 1 1 1 1
         *    1 0 0 1 0
         *
         * dp[i][j]: The length of the largest square that uses the cell (i, j)
         *           as the bottom-right corner.
         *
         * dp[i][j] = Min| dp[i - 1][j]     + 1, if matrix[i][j] == 1
         *               | dp[i][j - 1]
         *               | dp[i - 1][j - 1]
         *
         * dp[2][2] = Min | dp[1][2] + 1 = 1
         *                | dp[2][1]
         *                | dp[1][1]
         *
         */

        int num_r = matrix.size();
        if (num_r == 0) {
            return 0;
        }

        int num_c = matrix[0].size();
        if (num_c == 0) {
            return 0;
        }

        int len = 0;
        int dp[num_r][num_c] = {{0}};

        for (int i = 0 ; i < num_r ; ++i) {
            dp[i][0] = matrix[i][0];
            len = std::max(len, dp[i][0]);
        }
        for (int i = 0 ; i < num_c ; ++i) {
            dp[0][i] = matrix[0][i];
            len = std::max(len, dp[0][i]);
        }

        for (int i = 1 ; i < num_r ; ++i) {
            for (int j = 1 ; j < num_c ; ++j) {
                if (matrix[i][j] == 0) {
                    continue;
                }

                dp[i][j] = std::min(
                    std::min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                len = std::max(len, dp[i][j]);
            }
        }

        return len * len;
    }
};