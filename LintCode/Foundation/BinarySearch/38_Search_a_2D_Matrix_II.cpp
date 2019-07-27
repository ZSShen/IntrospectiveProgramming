class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @param target: An integer you want to search in matrix
     * @return: An integer indicate the total occurrence of target in the given matrix
     */
    int searchMatrix(vector<vector<int>> &matrix, int target) {
        // write your code here

        int num_r = matrix.size();
        if (num_r == 0) {
            return 0;
        }

        int num_c = matrix[0].size();
        if (num_c == 0) {
            return 0;
        }

        int count = 0;
        int x = 0, y = num_c - 1;
        while (x < num_r && y >= 0) {
            if (matrix[x][y] == target) {
                ++count;
            }

            if (target <= matrix[x][y]) {
                --y;
            } else {
                ++x;
            }
        }

        return count;
    }
};