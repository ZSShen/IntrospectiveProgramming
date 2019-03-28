class Solution {
public:
    /**
     * @param matrix: matrix, a list of lists of integers
     * @param target: An integer
     * @return: a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        // write your code here

        int num_row = matrix.size();
        if (num_row == 0) {
            return false;
        }

        int num_col = matrix[0].size();
        if (num_col == 0) {
            return false;
        }

        int r = 0, c = num_col - 1;
        while (r < num_row && c >= 0) {
            if (matrix[r][c] == target) {
                return true;
            }
            if (target > matrix[r][c]) {
                ++r;
            } else {
                --c;
            }
        }

        return false;
    }
};