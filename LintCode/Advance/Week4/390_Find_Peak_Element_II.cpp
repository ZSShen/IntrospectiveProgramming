class Solution {
public:
    /*
     * @param A: An integer matrix
     * @return: The index of the peak
     */
    vector<int> findPeakII(vector<vector<int>> &A) {
        // write your code here

        int num_r = A.size();
        if (num_r == 0) {
            return {-1, -1};
        }

        int num_c = A[0].size();
        if (num_c == 0) {
            return {-1, -1};
        }

        for (int i = 0 ; i < num_r ; ++i) {

            int l = 0, r = num_c - 1;
            while (l + 1 < r) {
                int m = l + (r - l) / 2;

                if (A[i][m] < A[i][m + 1]) {
                    l = m;
                } else {
                    r = m;
                }
            }

            int j = (A[i][l] < A[i][r]) ? r : l;

            bool check = true;
            if (i > 0 && A[i][j] < A[i - 1][j]) {
                check = false;
            }
            if (check && i < num_r - 1 && A[i][j] < A[i + 1][j]) {
                check = false;
            }

            if (check) {
                return {i, j};
            }
        }

        return {-1, -1};
    }
};