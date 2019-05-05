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


class Solution {
public:
    /**
     * @param matrix: the given matrix
     * @return: the largest possible sum
     */
    int maxSubmatrix(vector<vector<int>> &matrix) {
        // write your code here

        /**
         *
         *  i        j
         *  a1  b1  c1  d1      s1 (a1 + b1 + c1)
         *  a2  b2  c2  d2      s2
         *  a3  b3  c3  d3      s3                    s2    a2 b2 c2
         *  .   .   .   .    => .                 =>  .  => .  .  .
         *  .   .   .   .       .                     sk    ak bk ck
         *  an  bn  cn  dn      sn
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

        int ans = std::numeric_limits<int>::min();

        for (int i = 0 ; i < num_c ; ++i) {

            std::vector<int> syn(num_r, 0);

            for (int j = i ; j < num_c ; ++j) {

                // Initialize a new synthetic array.
                for (int k = 0 ; k < num_r ; ++k) {
                    syn[k] += matrix[k][j];
                }

                int local = maxSubarray(syn);
                ans = std::max(ans, local);
            }
        }

        return ans;
    }

private:
    int maxSubarray(
            const std::vector<int>& array) {

        /**
         *   A, B
         *
         *   A > 0, B > 0, A + B
         *   A > 0, B < 0, A + B < A
         */

        int size = array.size();

        int ans = array[0];
        int local = 0;

        for (int num : array) {
            local += num;

            ans = std::max(ans, local);

            if (local < 0) {
                local = 0;
            }
        }

        return ans;
    }
};