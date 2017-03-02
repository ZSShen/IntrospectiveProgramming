class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int numRow = matrix.size();
        if (numRow == 0) {
            return 0;
        }

        int numCol = matrix[0].size();
        if (numCol == 0) {
            return 0;
        }

        std::vector<std::vector<int>> memo(numRow, 
            std::vector<int>(numCol, 0));

        int max = 0;
        for (int i = 0 ; i < numRow ; ++i) {
            for (int j = 0 ; j < numCol ; ++j) {
                int local = lipBeginAt(i, j, numRow, numCol, 
                    matrix, memo);                    
                if (local > max) {
                    max = local;
                }
            }
        }

        return max;
    }

private:
    int lipBeginAt(int row, int col, int numRow, int numCol,
            std::vector<std::vector<int>>& matrix,
            std::vector<std::vector<int>>& memo) {

        if (memo[row][col] > 0) {
            return memo[row][col];
        }

        int currElem = matrix[row][col];

        if (row > 0 && matrix[row - 1][col] > currElem) {
            int lip = lipBeginAt(row - 1, col, numRow, numCol,
                matrix, memo);
            if (lip > memo[row][col]) {
                memo[row][col] = lip;
            }
        }

        if (col > 0 && matrix[row][col - 1] > currElem) {
            int lip = lipBeginAt(row, col - 1, numRow, numCol,
                matrix, memo);
            if (lip > memo[row][col]) {
                memo[row][col] = lip;
            }
        }

        if (row < numRow - 1 && matrix[row + 1][col] > currElem) {
            int lip = lipBeginAt(row + 1, col, numRow, numCol,
                matrix, memo);
            if (lip > memo[row][col]) {
                memo[row][col] = lip;
            }
        }

        if (col < numCol - 1 && matrix[row][col + 1] > currElem) {
            int lip = lipBeginAt(row, col + 1, numRow, numCol,
                matrix, memo);
            if (lip > memo[row][col]) {
                memo[row][col] = lip;
            }
        }

        return ++memo[row][col];
    }
};