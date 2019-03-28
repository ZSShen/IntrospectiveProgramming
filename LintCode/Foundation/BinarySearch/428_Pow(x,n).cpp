class Solution {
public:
    /**
     * @param x: the base number
     * @param n: the power number
     * @return: the result
     */
    double myPow(double x, int n) {
        // write your code here

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