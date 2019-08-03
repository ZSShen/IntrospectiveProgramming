class Solution {
public:
    /**
     * @param x: the base number
     * @param n: the power number
     * @return: the result
     */
    double myPow(double x, int n) {
        // write your code here

        /**
         *   n^8 = n^4 x n^4
         *       = (n^2 x n^2) x (n^2 x n^2)
         *
         *   n^9 = n^8 x n
         *         ---
         *
         *  Corner Case: n maybe -2147483648
         *               That's way we use long type to store the exponential.
         */

        if (n == 0) {
            return 1;
        }

        long nn = n;
        return (n > 0) ? genPow(x, nn) : 1 / genPow(x, -nn);
    }

private:
    double genPow(double x, long n) {

        if (n == 1) {
            return x;
        }

        long d = n >> 1;
        double half = genPow(x, d);

        double res = half * half;
        if (d << 1 != n) {
            res *= x;
        }

        return res;
    }
};