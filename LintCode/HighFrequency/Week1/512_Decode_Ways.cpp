class Solution {
public:
    /**
     * @param s: a string,  encoded message
     * @return: an integer, the number of ways decoding
     */
    int numDecodings(string &s) {
        // write your code here

        /**
         * dp[i]: The number of ways to decode the prefix ending at index i.
         *
         * dp[i] = dp[i - 1] + dp[i - 2]
         *
         * - Handle 1 digit:
         *   s[i]: 0              -> 0
         *   s[i]: {1, 2, ..., 9} -> 1
         *
         * - Handle 2 digits:
         *   s[i - 1]: 0                  -> 0
         *   s[i - 1]: 1
         *      - s[i]: {0, 1, 2, ..., 9} -> 1
         *   s[i - 1]: 2
         *      - s[i]: {0, 1, 2, ..., 6} -> 1
         *      - s[i]: {7, 8, 9}         -> 0
         *   s[i - 1]: {3, 4, ..., 9}     -> 0
         */

        int n = s.length();
        if (n == 0) {
            return 0;
        }

        std::vector<int> dp(n + 1, 1);

        for (int i = 1 ; i <= n ; ++i) {

            dp[i] = countOneDigit(s, i - 1) * dp[i - 1];
            if (i >= 2) {
                dp[i] += countTwoDigits(s, i - 2, i - 1) * dp[i - 2];
            }
        }

        return dp[n];
    }

private:
    int countOneDigit(const std::string& str, int s1) {

        return (str[s1] == '0') ? 0 : 1;
    }

    int countTwoDigits(const std::string& str, int s1, int s2) {

        if (str[s1] == '0') {
            return 0;
        }

        if (str[s1] == '1') {
            return 1;
        }

        if (str[s1] == '2') {
            return ('0' <= str[s2] && str[s2] <= '6') ? 1 : 0;
        }

        return 0;
    }
};