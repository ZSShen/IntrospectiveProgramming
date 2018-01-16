class Solution {
    public double myPow(double x, int n) {

        long exp = n;
        if (exp < 0) {
            exp = -exp;
            return 1 / fastPow(x, exp);
        }
        return fastPow(x, exp);
    }

    private double fastPow(double x, long exp) {

        if (exp == 0) {
            return 1;
        }

        double half = fastPow(x, exp >> 1);
        double result = half * half;

        if (exp % 2 == 1) {
            result *= x;
        }

        return result;
    }
}