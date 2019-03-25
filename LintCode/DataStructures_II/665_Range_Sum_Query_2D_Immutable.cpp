class NumMatrix {
private:
    int num_row_;
    int num_col_;
    std::vector<std::vector<int>> prefix_;

public:
    NumMatrix(vector<vector<int>> matrix)
        : num_row_(matrix.size()),
          num_col_(matrix[0].size()),
          prefix_(num_row_ + 1, std::vector<int>(num_col_ + 1, 0)) {

        for (int i = 0 ; i < num_row_ ; ++i) {
            for (int j = 0 ; j < num_col_ ; ++j) {
                prefix_[i + 1][j + 1] =
                        matrix[i][j] +
                        prefix_[i + 1][j] + prefix_[i][j + 1] -
                        prefix_[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {

        return prefix_[row2 + 1][col2 + 1] -
               prefix_[row1][col2 + 1] -
               prefix_[row2 + 1][col1] +
               prefix_[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */