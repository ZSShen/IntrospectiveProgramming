class Solution {
public:
    Solution()
      : max_int(std::numeric_limits<int>::max())
    { }

    /**
     * @param dividend: the dividend
     * @param divisor: the divisor
     * @return: the result
     */
    int divide(int dividend, int divisor) {
        // write your code here

        long divd = static_cast<long>(dividend);
        if (divd < 0) {
            divd = -divd;
        }
        long divr = static_cast<long>(divisor);
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

        if (quot >= max_int) {
            return max_int;
        }

        return quot;
    }

private:
    int max_int;
};