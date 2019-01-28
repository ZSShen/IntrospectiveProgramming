class Solution {
public:
    int mySqrt(int x)
    {
        if (x == 0)
            return 0;
        if (x == 1)
            return 1;

        int bgn = 1, end = x >> 1, mid;
        while (bgn <= end) {
            mid = (bgn + end) >> 1;
            if (mid > INT_MAX / mid) {
                end = mid - 1;
                continue;
            }
            int val = mid * mid;
            if (val == x)
                return mid;
            else {
                if (val > x)
                    end = mid - 1;
                else
                    bgn = mid + 1;
            }
        }

        return (mid <= x / mid) ? mid : (mid - 1);
    }
};