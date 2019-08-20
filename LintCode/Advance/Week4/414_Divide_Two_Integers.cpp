class Solution {
public:
    /**
     * @param dividend: the dividend
     * @param divisor: the divisor
     * @return: the result
     */
    int divide(int dividend, int divisor) {
        // write your code here

        long divd = static_cast<long>(dividend);
        long divr = static_cast<long>(divisor);

        if (divd < 0) {
            divd = -divd;
        }
        if (divr < 0) {
            divr = -divr;
        }

        long quot = 0;
        while (divd >= divr) {
            long temp = divr;
            long count = 1;

            while (divd >= (temp << 1)) {
                temp <<= 1;
                count <<= 1;
            }

            quot += count;
            divd -= temp;
        }

        if ((dividend > 0) ^ (divisor > 0) > 0) {
            quot = -quot;
        }

        return (quot > INT_MAX) ? INT_MAX : quot;
    }
};