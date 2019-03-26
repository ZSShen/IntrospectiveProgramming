class Solution {
public:
    /**
     * @param matrix: the given matrix
     * @return: the largest possible sum
     */
    int maxSubmatrix(vector<vector<int>> &matrix) {
        // write your code here

        int num_row = matrix.size();
        if (num_row == 0) {
            return 0;
        }
        int num_col = matrix[0].size();
        if (num_col == 0) {
            return 0;
        }

        int max = matrix[0][0];

        for (int i = 0 ; i < num_col ; ++i) {
            std::vector<int> syn(num_row, 0);

            for (int j = i ; j < num_col ; ++j) {
                for (int k = 0 ; k < num_row ; ++k) {
                    syn[k] += matrix[k][j];
                }

                int sum = 0;
                int local = syn[0];
                for (int num : syn) {
                    sum += num;
                    local = std::max(sum, local);
                    if (sum < 0) {
                        sum = 0;
                    }
                }

                max = std::max(local, max);
            }
        }

        return max;
    }
};