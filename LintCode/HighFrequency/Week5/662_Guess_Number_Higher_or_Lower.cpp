// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    /**
     * @param n an integer
     * @return the number you guess
     */
    int guessNumber(int n) {
        // Write your code here

        long l = 1, r = n;
        while (l + 1 < r) {
            long m = (l + r) / 2;

            int res = guess(m);
            if (res == 0) {
                return m;
            }

            if (res == -1) {
                r = m;
            } else {
                l = m;
            }
        }

        if (guess(l) == 0) {
            return l;
        }
        return r;
    }
};