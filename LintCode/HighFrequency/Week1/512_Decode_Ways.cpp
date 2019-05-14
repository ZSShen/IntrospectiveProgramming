class Solution {
public:
    /**
     * @param s: a string,  encoded message
     * @return: an integer, the number of ways decoding
     */
    int numDecodings(string &s) {
        // write your code here

        /**
         *   123
         *   AW  => f(n) = f(n - 1) + f(n - 2)
         *   LC
         *
         *   10 -> 26
         **/

        int size = s.length();
        if (size == 0) {
            return 0;
        }

        std::vector<int> dp(size + 1);
        // For dummy initialization.
        dp[0] = 1;
        // For the first digit.
        dp[1] = (s[0] != '0') ? 1 : 0;

        for (int i = 2 ; i <= size ; ++i) {

            dp[i] = (s[i - 1] != '0') ? dp[i - 1] : 0;

            if (s[i - 2] == '1' && ('0' <= s[i - 1] && s[i - 1] <= '9')) {
                dp[i] += dp[i - 2];
            } else if (s[i - 2] == '2' && ('0' <= s[i - 1] && s[i - 1] <= '6')) {
                dp[i] += dp[i - 2];
            }
        }

        return dp[size];
    }
};