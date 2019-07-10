class Solution {
public:
    /**
     * @param x: a double
     * @return: the square root of x
     */
    double sqrt(double x) {
        // write your code here

        double l = 0;
        double r = std::max(x, 1.0);
        double epsilon = 1e-10;

        while (l + epsilon < r) {
            double m = l + (r - l) / 2;
            if (m * m < x) {
                l = m;
            } else {
                r = m;
            }
        }

        return l;
    }
};


class Solution {
public:
    /**
     * @param x: a double
     * @return: the square root of x
     */
    double sqrt(double x) {
        // write your code here

        if (x == 0) {
            return 0;
        }

        double l = (x >= 1) ? 1 : 0;
        double r = (x >= 1) ? x : 1;

        while (l + 1e-10 < r) {
            double m = l + (r - l) / 2;

            double test = x / m;
            if (test >= m) {
                l = m;
            } else {
                r = m;
            }
        }

        return (x / r > r) ? r : l;
    }
};