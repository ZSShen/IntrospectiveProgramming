class Solution {
public:
    /**
     * @param A: an integer rotated sorted array
     * @param target: an integer to be searched
     * @return: an integer
     */
    int search(vector<int> &A, int target) {
        // write your code here

        int n = A.size();
        if (n == 0) {
            return -1;
        }

        int l = 0, r = n - 1;

        while (l + 1 < r) {
            int m = l + (r - l) / 2;

            if (A[m] < A[r]) {
                // The right portion is sorted.
                if (A[m] <= target && target <= A[r]) {
                    l = m;
                } else {
                    r = m;
                }
            } else if (A[l] < A[m]) {
                // The left portion is sorted.
                if (A[l] <= target && target <= A[m]) {
                    r = m;
                } else {
                    l = m;
                }
            }
        }

        if (target == A[l]) {
            return l;
        } else if (target == A[r]) {
            return r;
        }
        return -1;
    }
};