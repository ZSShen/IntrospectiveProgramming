class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int num_row = matrix.size();
        if (num_row == 0)
            return false;
        int num_col = matrix[0].size();
        if (num_col == 0)
            return false;

        // First locate the possible row.
        int bgn = 0, end = num_row - 1, mid;
        while (bgn <= end) {
            mid = (bgn + end) >> 1;
            if (matrix[mid][0] == target)
                return true;
            if (matrix[mid][0] < target) {
                if (mid < (num_row - 1) && target < matrix[mid + 1][0])
                    break;
                bgn = mid + 1;
            }
            if (matrix[mid][0] > target)
                end = mid - 1;
        }

        // Then pinpoint the target.
        vector<int>& row = matrix[mid];
        bgn = 0;
        end = num_col - 1;
        while (bgn <= end) {
            mid = (bgn + end) >> 1;
            if (row[mid] < target)
                bgn = mid + 1;
            else if (row[mid] > target)
                end = mid - 1;
            else
                return true;
        }
        return false;
    }
};
