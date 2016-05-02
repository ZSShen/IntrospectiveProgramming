// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n)
    {
        if (n == 0)
            return 0;

        unsigned int bgn = 1, end = n, mid;
        while (bgn < end) {
            mid = (bgn + end) >> 1;
            if (isBadVersion(mid))
                end = mid;
            else
                bgn = mid + 1;
        }

        return static_cast<int>(bgn);
    }
};