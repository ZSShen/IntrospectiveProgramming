class Solution {
public:
    int numDecodings(string s) {
        /**
         * The recursive formula (ignoring ill-formed substrings):
         * 
         * Let dp[i]: The number of decode ways ending at offset i.
         * 
         *         | dp[i - 2] + dp[i - 1], if s(i-1, i) ranging 
         * dp[i] = |                        from "11" to "19" and from "21" to "26".
         *         | dp[i - 1]            , if s(i) raning from "1" to "9",
         *         |                        or s(i-1, i) = "10" or "20".
         * 
         * Ill-formed substrings:
         *      1. Consecutive 0s.
         *      2. n0, where n >= 3.
         */

        int length = s.length();
        if (length == 0) {
            return 0;
        }
        if (length == 1) {
            return (s[0] != '0')? 1 : 0;
        }
        if (s[0] == '0') {
            return 0;
        }
        if (s[0] >= '3' && s[1] == '0') {
            return 0;
        }

        std::vector<int> dp(length, 0);

        // First prepare the boundary calculation.
        dp[0] = 1;
        if ((s[0] == '1' && s[1] >= '1') || 
            (s[0] == '2' && (s[1] >= '1' && s[1] <= '6'))) {
            dp[1] = 2;
        } else {
            dp[1] = 1;
        }

        // Run the look-back accumulation.
        for (int i = 2 ; i < length ; ++i) {
            // Early return for ill-formed string.
            if (s[i - 1] == '0' && s[i] == '0') {
                return 0;
            }
            if (s[i - 1] >= '3' && s[i] == '0') {
                return 0;
            }

            if ((s[i - 1] == '1' && s[i] >= '1') || 
                (s[i - 1] == '2' && (s[i] >= '1' && s[i] <= '6'))) {
                dp[i] = dp[i - 2] + dp[i - 1];
            } else if (s[i] > '0') {
                dp[i] = dp[i - 1];
            } else {
                dp[i] = dp[i - 2];
            }
        }

        return dp[length - 1];
    }
};