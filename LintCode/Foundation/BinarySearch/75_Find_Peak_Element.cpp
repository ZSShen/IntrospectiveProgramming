class Solution {
public:
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int> &A) {
        // write your code here

        int size = A.size();
        int l = 0, r = size - 1;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (A[m] < A[m + 1]) {
                l = m;
            } else {
                r = m;
            }
        }

        return (A[l] > A[r]) ? l : r;
    }
};