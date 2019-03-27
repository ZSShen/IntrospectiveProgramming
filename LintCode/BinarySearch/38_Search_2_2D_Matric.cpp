class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @param target: An integer you want to search in matrix
     * @return: An integer indicate the total occurrence of target in the given matrix
     */
    int searchMatrix(vector<vector<int>> &matrix, int target) {
        // write your code here

        int num_row = matrix.size();
        if (num_row == 0) {
            return 0;
        }

        int num_col = matrix[0].size();
        if (num_col == 0) {
            return 0;
        }

        int count = 0;
        int r = 0, c = num_col - 1;
        while (r < num_row && c >= 0) {
            if (matrix[r][c] == target) {
                ++count;
            }

            if (target > matrix[r][c]) {
                ++r;
            } else {
                --c;
            }
        }

        return count;
    }
};