class Solution {
public:
    /**
     * @param A: An integer array
     * @param start: An integer
     * @param end: An integer
     * @return: the number of possible answer
     */
    int subarraySumII(vector<int> &A, int start, int end) {
        // write your code here

        /**
         *       a1, a2, ..., an
         *   S0, S1, S2, ..., Sn
         *
         *          start <= Si - Sj <= end
         *   S0, S1, Sj, ..., Si, ...
         *
         *
         *   l: The first proper position
         *   r: The position next to the last proper position
         *
         *   Si - Sr < start
         *   Si - Sl <= end
         *
         *   S0, Sl, S2, .Sr., Si, ...
         */

        int n = A.size();
        if (n == 0) {
            return 0;
        }

        std::vector<int> prefix(n + 1, 0);
        for (int i = 1 ; i <= n ; ++i) {
            prefix[i] = prefix[i - 1] + A[i - 1];
        }

        int count = 0, l = 0, r = 0;
        for (int i = 1 ; i <= n ; ++i) {

            // Pinpoint the lower bound.
            while (r < i && prefix[i] - prefix[r] >= start) {
                ++r;
            }

            // Pinpoint the upper bound.
            while (l < i && prefix[i] - prefix[l] > end) {
                ++l;
            }

            count += r - l;
        }

        return count;
    }
};