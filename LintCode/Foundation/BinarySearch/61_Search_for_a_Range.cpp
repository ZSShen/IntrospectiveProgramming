class Solution {
public:
    /**
     * @param A: an integer sorted array
     * @param target: an integer to be inserted
     * @return: a list of length 2, [index1, index2]
     */
    vector<int> searchRange(vector<int> &A, int target) {
        // write your code here

        int size = A.size();
        if (size == 0) {
            return {-1, -1};
        }

        int bgn = 0;
        int end = size - 1;
        while (bgn + 1 < end) {
            int mid = bgn + (end - bgn) / 2;
            if (A[mid] == target) {
                bgn = mid;
                break;
            }

            if (target > A[mid]) {
                bgn = mid;
            } else {
                end = mid;
            }
        }

        if (A[bgn] == target) {
            return findRange(A, bgn, target);
        }
        if (A[end] == target) {
            return findRange(A, end, target);
        }

        return {-1, -1};
    }

private:
    std::vector<int> findRange(
            const std::vector<int>& nums, int start, int target) {

        int bgn = start, end = start;
        while (bgn >= 0 && nums[bgn] == target) {
            --bgn;
        }
        ++bgn;

        while (end < nums.size() && nums[end] == target) {
            ++end;
        }
        --end;

        return {bgn, end};
    }
};