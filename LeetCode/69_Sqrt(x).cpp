class Solution {
public:
    int mySqrt(int x) {

        if (x <= 1) {
            return x;
        }

        int left = 1;
        int right = x >> 1;

        while (left <= right) {
            int mid = (left + right) >> 1;

            int test = x / mid;
            if (mid == test) {
                return mid;
            }

            if (mid > test) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return (left < x / left)? left : (left - 1);
    }
};