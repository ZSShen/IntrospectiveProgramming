class Solution {
public:
    /**
     * @param A: a sparse matrix
     * @param B: a sparse matrix
     * @return: the result of A * B
     */
    vector<vector<int>> multiply(vector<vector<int>> &A, vector<vector<int>> &B) {
        // write your code here

        int m = A.size();
        int n = A[0].size();
        int t = B[0].size();

        std::vector<std::vector<int>> nonzero(n, std::vector<int>());
        for (int i = 0 ; i < n ; ++i) {
            for (int j = 0 ; j < t ; ++j) {
                if (B[i][j] != 0) {
                    nonzero[i].push_back(j);
                }
            }
        }

        std::vector<std::vector<int>> C(m, std::vector<int>(t, 0));
        for (int i = 0 ; i < m ; ++i) {
            for (int j = 0 ; j < n ; ++j) {
                if (A[i][j] == 0) {
                    continue;
                }
                for (int k : nonzero[j]) {
                    C[i][k] += A[i][j] * B[j][k];
                }
            }
        }

        return C;
    }
};