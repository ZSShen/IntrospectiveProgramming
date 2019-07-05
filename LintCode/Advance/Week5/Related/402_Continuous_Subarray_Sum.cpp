class Solution {
public:
    /*
     * @param A: An integer array
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> continuousSubarraySum(vector<int> &A) {
        // write your code here

        int n = A.size();
        if (n == 0) {
            return {-1, -1};
        }

        int max = A[0], max_bgn = 0, max_end = 0;
        int sum = 0, bgn = 0, end = 0;

        while (end < n) {
            sum += A[end];

            if (sum > max) {
                max = sum;
                max_bgn = bgn;
                max_end = end;
            }

            ++end;

            /**
             * A, B
             *
             * A > 0, B > 0,           A + B > A
             * A > 0, B < 0, |B| > A,  A + B < 0
             */

            if (sum < 0) {
                sum = 0;
                bgn = end;
            }
        }

        return {max_bgn, max_end};
    }
};