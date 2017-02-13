class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        /**
         *  The recusive fomula:
         * 
         *  Let dp[i][j] : The maximal square formed by using (i, j)
         *                 as the upper left corner.
         * 
         * dp[i][j] = Min{dp[i + 1][j], dp[i][j + 1], dp[i + 1][j + 1]} + 1
         */

        int numRow = matrix.size();
        if (numRow == 0) {
            return 0;
        }
        int numCol = matrix[0].size();
        if (numCol == 0) {
            return 0;
        }

        std::vector<std::vector<int>> dp(numRow, std::vector<int>(numCol));
        int max = 0;
        for (int i = 0 ; i < numCol ; ++i) {
            int element = matrix[numRow - 1][i] - '0';
            dp[numRow - 1][i] = element;
            if (element > max) {
                max = element;
            }
        }
        for (int i = 0 ; i < numRow ; ++i) {
            int element = matrix[i][numCol - 1] - '0';
            dp[i][numCol - 1] = element;
            if (element > max) {
                max = element;
            }
        }

        if (numRow == 1 || numCol == 1) {
            return max;
        }

        for (int i = numRow - 2 ; i >= 0 ; --i) {
            for (int j = numCol - 2 ; j >= 0 ; --j) {
                if (matrix[i][j] == '0') {
                    dp[i][j] = 0;
                    continue;
                }

                int local = dp[i + 1][j];
                if (dp[i][j + 1] < local) {
                    local = dp[i][j + 1];
                }
                if (dp[i + 1][j + 1] < local) {
                    local = dp[i + 1][j + 1];
                }
                ++local;
                dp[i][j] = local;
                if (local > max) {
                    max = local;
                }
            }
        }

        return max * max;
    }
};