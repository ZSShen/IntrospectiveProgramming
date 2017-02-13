class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        }

        long remain = n;
        bool reverse = false;
        if (remain < 0) {
            remain = -remain;
            reverse = true;
        }

        double ans = 1;
        double temp;
        long times;

        while (remain > 1) {
            temp = x * x;
            times = 2;
            do {
                long test = times << 1;
                if (test > remain) {
                    break;
                }
                temp *= temp;
                times = test;
            } while (true);

            ans *= temp;
            remain -= times;
        }
        if (remain == 1) {
            ans *= x;
        }

        return (reverse == false)? ans : 1 / ans;
    }
};