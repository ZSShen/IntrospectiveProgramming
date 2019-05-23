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