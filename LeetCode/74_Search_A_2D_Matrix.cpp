class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int numRow = matrix.size();
        if (numRow == 0) {
            return false;
        }

        int numCol = matrix[0].size();
        if (numCol == 0) {
            return false;
        }

        int left = 0;
        int right = numRow * numCol - 1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            int row = mid / numCol;
            int col = mid % numCol;
            int num = matrix[row][col];

            if (num == target) {
                return true;
            }
            if (target > num) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return false;
    }
};