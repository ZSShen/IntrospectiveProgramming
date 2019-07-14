class Solution {
public:
    Solution()
      : mod(1000000007)
    { }

    /**
     * @param s: a message being encoded
     * @return: an integer
     */
    int numDecodings(string &s) {
        // write your code here

        /**
         *            i
         *      *******
         *           (i - 1)
         *  ->  ******
         *           (i - 2)
         *  ->  *****
         *
         *  dp[i]: The number of ways to decode the given substring ending at
         *         the ith letter.
         *
         *  dp[i] = dp[i - 1] + dp[i - 2]
         *
         *
         *  dp[i - 1]:
         *      - s[i]: 0           , get 0
         *      - s[i]: {1, ..., 9} , get dp[i - 1]
         *      - s[i]: *           , get 9 * dp[i - 1]
         *
         *  dp[i - 2]:
         *      - s[i - 1]: 0           , get 0
         *      - s[i - 1]: 1
         *          - s[i]: {0, ..., 9} , get dp[i - 2]
         *          - s[i]: *           , get 9 * dp[i - 2]
         *      - s[i - 1]: 2
         *          - s[i]: {0, ..., 6} , get dp[i - 2]
         *          - s[i]: {7, 8, 9}   , get 0
         *          - s[i]: *           , get 6 * dp[i - 2]
         *      - s[i - 1]: {3, ..., 9} , get 0
         *      - s[i - 1]: *
         *          - s[i]: {0, ..., 6} , get 2 * dp[i - 2]
         *          - s[i]: {7, 8, 9}   , get dp[i - 2]
         *          - s[2]: *           , get 15 * dp[i - 2]
         *
         */

        int n = s.length();

        if (n == 0) {
            return 0;
        }

        std::vector<long> dp(n + 1, 0);
        dp[0] = 1;

        for (int i = 0, j = 1 ; i < n ; ++i, ++j) {

            if (i == 0) {
                dp[j] = countOneDigit(s, i) * dp[j - 1];
                continue;
            }

            dp[j] = (countOneDigit(s, i) * dp[j - 1] +
                    countTwoDigits(s, i - 1, i) * dp[j - 2]) % mod;

        }

        return dp[n] % mod;
    }

private:
    int countOneDigit(const std::string& s, int p1) {

        if (s[p1] == '0') {
            return 0;
        }

        if ('1' <= s[p1] && s[p1] <= '9') {
            return 1;
        }

        return 9;
    }

    int countTwoDigits(const std::string& s, int p1, int p2) {

        if (s[p1] == '0') {
            return 0;
        }

        if (s[p1] == '1') {
            if ('0' <= s[p2] && s[p2] <= '9') {
                return 1;
            }

            if (s[p2] == '*') {
                return 9;
            }
        }

        if (s[p1] == '2') {
            if ('0' <= s[p2] && s[p2] <= '6') {
                return 1;
            }

            if ('7' <= s[p2] && s[p2] <= '9') {
                return 0;
            }

            if (s[p2] == '*') {
                return 6;
            }
        }

        if ('3' <= s[p1] && s[p1] <= '9') {
            return 0;
        }

        // Here, s[p1] == '*'.

        if ('0' <= s[p2] && s[p2] <= '6') {
            return 2;
        }

        if ('7' <= s[p2] && s[p2] <= '9') {
            return 1;
        }

        if (s[p2] == '*') {
            return 15;
        }
    }

    int mod;
};
