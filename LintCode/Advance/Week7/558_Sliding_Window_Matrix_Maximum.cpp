class Solution {
public:
    /**
     * @param matrix: an integer array of n * m matrix
     * @param k: An integer
     * @return: the maximum number
     */
    int maxSlidingMatrix(vector<vector<int>> &matrix, int k) {
        // write your code here

        /**
         *  k = 2
         *
         *  a b c d
         *  e f g h => (a+e) (b+f) (c+g) (d+h)
         *  i j k l    i     j     k     l
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

        if (num_r < k || num_c < k) {
            return 0;
        }

        std::vector<int> syn(num_c, 0);
        for (int i = 0 ; i < k ; ++i) {
            for (int j = 0 ; j < num_c ; ++j) {
                syn[j] += matrix[i][j];
            }
        }

        int ans = INT_MIN;

        int bgn_r = 0, end_r = k - 1;
        while (true) {

            // Scan the 1d vector.
            int rtn = scanRow(syn, k, num_c);
            ans = std::max(ans, rtn);

            if (end_r == num_r - 1) {
                break;
            }

            // Update the synthetic row.
            ++end_r;
            for (int j = 0 ; j < num_c ; ++j) {
                syn[j] -= matrix[bgn_r][j];
                syn[j] += matrix[end_r][j];
            }
            ++bgn_r;
        }

        return ans;
    }

private:
    int scanRow(std::vector<int>& syn, int k, int num_c) {

        int max = INT_MIN;

        // Reduce the 1d vector into a single varaible.
        int window = 0;
        for (int i = 0 ; i < k ; ++i) {
            window += syn[i];
        }

        int bgn_c = 0, end_c = k - 1;
        while (true) {
            max = std::max(max, window);

            if (end_c == num_c - 1) {
                break;
            }

            ++end_c;
            window -= syn[bgn_c];
            window += syn[end_c];
            ++bgn_c;
        }

        return max;
    }
};