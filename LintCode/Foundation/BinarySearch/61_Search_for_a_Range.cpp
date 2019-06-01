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


class Solution {
public:
    /**
     * @param A: an integer sorted array
     * @param target: an integer to be inserted
     * @return: a list of length 2, [index1, index2]
     */
    vector<int> searchRange(vector<int> &A, int target) {
        // write your code here

        int n = A.size();
        if (n == 0) {
            return {-1, -1};
        }

        // Find the lower bound.
        int l = 0, r = n - 1;
        while (l + 1 < r) {
            int m = (l + r) / 2;
            if (A[m] >= target) {
                r = m;
            } else {
                l = m;
            }
        }

        int bgn = -1;
        if (A[l] == target) {
            bgn = l;
        } else if (A[r] == target) {
            bgn = r;
        }

        if (bgn == -1) {
            return {-1, -1};
        }

        // Find the upper bound.
        l = 0, r = n - 1;
        while (l + 1 < r) {
            int m = (l + r) / 2;
            if (A[m] > target) {
                r = m;
            } else {
                l = m;
            }
        }

        int end = -1;
        if (A[r] == target) {
            end = r;
        } else if (A[l] == target) {
            end = l;
        }

        return {bgn, end};
    }
};