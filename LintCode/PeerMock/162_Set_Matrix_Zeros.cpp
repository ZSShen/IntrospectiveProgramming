class Solution {
public:
    /**
     * @param matrix: A lsit of lists of integers
     * @return: nothing
     */
    void setZeroes(vector<vector<int>> &matrix) {
        // write your code here
        
        int num_r = matrix.size();
        if (num_r == 0) {
            return;
        }
        
        int num_c = matrix[0].size();
        if (num_c == 0) {
            return;
        }
        

        /**
         *    1 1 0 1
         *    0 1 1 1
         *    1 0 1 1
         *    1 1 1 1
         * 
         *  Step 1. Check the outer frames.
         *   Fill 0s for the 1st row (yes)
         *   Fill 0s for the 1st column (yes)
         * 
         *  Step 2. Check the internal matrix and fill the leading rows and 
         *          columns with 0s for the cells that are now 0s.
         * 
         *    1 0 0 1
         *    0 1 1 1
         *    0 0 1 1
         *    1 1 1 1         
         * 
         *  Step 3. Fill the internal matrix with 0s by checking the leading 
         *          rows and columns.
         * 
         *    1 0 0 1
         *    0 0 0 0
         *    0 0 0 0
         *    1 0 0 1     
         * 
         *  Step 4. Based on the result determined in the 1st step, we should
         *          fill the first row and column with 0s if necessary.
         * 
         *    0 0 0 0
         *    0 0 0 0
         *    0 0 0 0
         *    0 0 0 1             
         */ 

        bool must_fill_1st_row = false;
        for (int i = 0 ; i < num_c ; ++i) {
            if (matrix[0][i] == 0) {
                must_fill_1st_row = true;
                break;
            }
        }

        bool must_fill_1st_col = false;
        for (int i = 0 ; i < num_r ; ++i) {
            if (matrix[i][0] == 0) {
                must_fill_1st_col = true;
                break;
            }
        }
        
        for (int i = 0 ; i < num_r ; ++i) {
            for (int j = 0 ; j < num_c ; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for (int i = 1 ; i < num_c ; ++i) {
            if (matrix[0][i] == 0) {
                for (int r = 1 ; r < num_r ; ++r) {
                    matrix[r][i] = 0;
                }
            }
        }
        
        for (int i = 1 ; i < num_r ; ++i) {
            if (matrix[i][0] == 0) {
                for (int c = 1 ; c < num_c ; ++c) {
                    matrix[i][c] = 0;
                }
            }
        }
        
        if (must_fill_1st_col) {
            for (int i = 0 ; i < num_r ; ++i) {
                matrix[i][0] = 0;
            }
        }
        if (must_fill_1st_row) {
            for (int i = 0 ; i < num_c ; ++i) {
                matrix[0][i] = 0;
            }
        }
    }
};