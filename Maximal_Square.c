int maximalSquare(char** matrix, int matrixRowSize, int matrixColSize)
{
    if (matrixRowSize == 0)
        return 0;

    int dp[matrixRowSize][matrixColSize];
    int max_width = 0;

    int idx_col = 0;
    while (idx_col < matrixColSize) {
        if (matrix[0][idx_col] == 1) {
            dp[0][idx_col] = 1;
            if (dp[0][idx_col] > max_width)
                max_width = dp[0][idx_col];
        } else
            dp[0][idx_col] = 0;
        idx_col++;
    }

    int idx_row = 0;
    while (idx_row < matrixRowSize) {
        if (matrix[idx_row][0] == 1) {
            dp[idx_row][0] = 1;
            if (dp[idx_row][0] > max_width)
                max_width = dp[idx_row][0];
        } else
            dp[idx_row][0] = 0;
        idx_row++;
    }

    idx_row = 1;
    while (idx_row < matrixRowSize) {
        idx_col = 1;
        while (idx_col < matrixColSize) {
            if (matrix[idx_row][idx_col] == 1) {
                if (matrix[idx_row - 1][idx_col] == 1 &&
                    matrix[idx_row][idx_col - 1] == 1 &&
                    matrix[idx_row - 1][idx_col - 1] == 1)
                    dp[idx_row][idx_col] = dp[idx_row - 1][idx_col - 1] + 1;
                else
                    dp[idx_row][idx_col] = 1;

                if (dp[idx_row][idx_col] > max_width)
                    max_width = dp[idx_row][idx_col];
            } else
                dp[idx_row][idx_col] = 0;

            idx_col++;
        }
        idx_row++;
    }

    return max_width * max_width;
}