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


class Solution {
public:
    /*
     * @param matrix: an integer matrix
     * @return: the coordinate of the left-up and right-down number
     */
    vector<vector<int>> submatrixSum(vector<vector<int>> &matrix) {
        // write your code here

        /**
         *  prefix(i) = array[0] + array[1] + ... + array[i];
         *  sum(i, j) = prefix(j) - prefix(i - 1)
         *  sum(i, j) = 0 => prefix(j) = prefix(i - 1)
         *
         *   a b c d      (a + b) -> A
         *   e f g h  =>  (e + f) -> B
         *   i j k l      (i + j) -> C
         *   m n o p      (m + n) -> D
         *
         *   Suppose that we want to scan the matrixes spanning from the
         *   first 2 columns, we can generate a synthetic column which merges
         *   these 2 columns and then apply the 1D solution we use to solve
         *   subarray sum problem to scan this synthetic column.
         *
         *   O(C^2 * R)
         */

        int num_r = matrix.size();
        int num_c = matrix[0].size();

        for (int i = 0 ; i < num_c ; ++i) {

            std::vector<int> syn(num_r, 0);

            for (int j = i ; j < num_c ; ++j) {

                // Generate a new synthetic array.
                for (int k = 0 ; k < num_r ; ++k) {
                    syn[k] += matrix[k][j];
                }

                auto res = subarraySum(syn);
                if (res[0] == -1 && res[1] == -1) {
                    continue;
                }

                return {{res[0], i}, {res[1], j}};
            }
        }

        return {{-1, -1}, {-1, -1}};
    }

private:
    std::vector<int> subarraySum(
            const std::vector<int>& array) {

        int size = array.size();

        std::unordered_map<int, int> match;
        match[0] = -1;

        int sum = 0;
        for (int i = 0 ; i < size ; ++i) {

            sum += array[i];

            if (match.count(sum) == 0) {
                match[sum] = i;
            } else {
                return {match[sum] + 1, i};
            }
        }

        return {-1, -1};
    }

};