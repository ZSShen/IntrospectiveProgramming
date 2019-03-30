class Solution {
public:
    /**
     * @param A: A an integer array sorted in ascending order
     * @param target: An integer
     * @return: An integer
     */
    int totalOccurrence(vector<int> &A, int target) {
        // write your code here

        int size = A.size();
        if (size == 0) {
            return 0;
        }

        int bgn = 0;
        int end = size - 1;
        while (bgn + 1 < end) {
            int mid = bgn + (end - bgn) / 2;
            if (A[mid] == target) {
                bgn = mid;
                break;
            }

            if (target < A[mid]) {
                end = mid;
            } else {
                bgn = mid;
            }
        }

        if (A[bgn] == target) {
            return countOccurance(A, target, bgn);
        }
        if (A[end] == target) {
            return countOccurance(A, target, end);
        }

        return 0;
    }

private:
    int countOccurance(
            const std::vector<int>& nums,
            int target,
            int mid) {

        int bgn = mid - 1;
        while (bgn >= 0 && target == nums[bgn]) {
            --bgn;
        }
        ++bgn;

        int end = mid + 1;
        while (end < nums.size() && target == nums[end]) {
            ++end;
        }
        --end;

        return end - bgn + 1;
    }
};