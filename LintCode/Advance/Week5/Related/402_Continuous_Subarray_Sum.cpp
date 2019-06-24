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

        int sum = 0;
        int max = A[0];
        int bgn = 0, end = 0, max_bgn = 0, max_end = 0;

        for (int i = 0 ; i < n ; ++i) {
            sum += A[i];

            if (sum > max) {
                max = sum;
                end = i;
                max_bgn = bgn;
                max_end = end;
            }

            /**
             *  A, n
             *
             * n > 0,           A + n > A
             * n < 0, |n| > A,  A + n < 0
             */

            if (sum < 0) {
                sum = 0 ;
                bgn = i + 1;
            }
        }

        return {max_bgn, max_end};
    }
};