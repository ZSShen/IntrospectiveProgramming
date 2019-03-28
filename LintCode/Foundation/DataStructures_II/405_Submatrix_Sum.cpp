class Solution {
public:
    /*
     * @param matrix: an integer matrix
     * @return: the coordinate of the left-up and right-down number
     */
    vector<vector<int>> submatrixSum(vector<vector<int>> &matrix) {
        // write your code here

        int num_row = matrix.size();
        if (num_row == 0) {
            return {};
        }

        int num_col = matrix[0].size();
        if (num_col == 0) {
            return {};
        }

        for (int i = 0 ; i < num_col ; ++i) {
            std::vector<int> syn(num_row, 0);

            for (int j = i ; j < num_col ; ++j) {

                // Prepare the synthetic array.
                for (int k = 0 ; k < num_row ; ++k) {
                    syn[k] += matrix[k][j];
                }

                // Try to find the synthetic subarray whose sum is 0.
                std::unordered_map<int, int> map;
                map[0] = -1;
                int sum = 0;
                for (int k = 0 ; k < num_row ; ++k) {
                    sum += syn[k];
                    if (map.count(sum) == 1) {
                        int row_bgn = map[sum] + 1;
                        int row_end = k;
                        int col_bgn = i;
                        int col_end = j;
                        return {{row_bgn, col_bgn}, {row_end, col_end}};
                    }
                    map[sum] = k;
                }
            }
        }

        return {};
    }
};