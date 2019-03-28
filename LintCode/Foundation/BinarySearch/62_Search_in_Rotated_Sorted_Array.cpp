class Solution {
public:
    /**
     * @param A: an integer rotated sorted array
     * @param target: an integer to be searched
     * @return: an integer
     */
    int search(vector<int> &A, int target) {
        // write your code here

        int size = A.size();
        if (size == 0) {
            return -1;
        }

        int l = 0, r = size - 1;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;

            if (target == A[m]) {
                return m;
            }

            if (A[m] < A[r]) {
                // The right portion is sorted.
                if (target >= A[m] && target <= A[r]) {
                    l = m;
                } else {
                    r = m;
                }
            } else {
                // The left portion is sorted.
                if (target <= A[m] && target >= A[l]) {
                    r = m;
                } else {
                    l = m;
                }
            }
        }

        if (A[l] == target) {
            return l;
        }
        if (A[r] == target) {
            return r;
        }
        return -1;
    }
};