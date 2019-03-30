class Solution {
public:
    /**
     * @param a: A 32bit integer
     * @param b: A 32bit integer
     * @param n: A 32bit integer
     * @return: An integer
     */
    int fastPower(int a, int b, int n) {
        // write your code here

        if (n == 0) {
            return 1 % b;
        }
        if (n == 1) {
            return a % b;
        }

        long result = fastPower(a, b, n >> 1);
        result = result * result % b;
        if (n % 2 == 1) {
            result = result * a % b;
        }

        return static_cast<int>(result);
    }
};