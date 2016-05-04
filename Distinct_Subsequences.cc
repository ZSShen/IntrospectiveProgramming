class Solution {
public:
    int numDistinct(string s, string t)
    {
        int len_t = t.length();
        int len_s = s.length();
        const char* cstr_t = t.c_str();
        const char* cstr_s = s.c_str();

        if (len_s == 0)
            return 0;

        // Let i denote the index of string t.
        //     j denote the index of string s.
        // Let dp[i][j] denote the combination count for the substring pair:
        //     the substring of t ending at index i and
        //     the substring of s ending at index j.

        // If t[i] == s[j], there are two situations:
        // 1. Chose characters at t[i] and s[j] and look up to the substring pair
        //    with removed t[i] and s[j] to check the combination count calculated
        //    so far.
        // 2. Do not choose the characters and look up to the substring pair
        //    with removed s[j] for checking.
        //
        // Otherwise:
        // 1. Do not choose the characters and look up to the substring pair
        //    with removed s[j] for checking.

        // dp[i][j] = | dp[i][j - 1] + dp[i - 1][j - 1], if t[i] == s[j]
        //            | dp[i][j - 1]                   , otherwise

        int dp[len_t + 1][len_s + 1];
        for (int j = 0 ; j <= len_s ; ++j)
            dp[0][j] = 1;

        for (int i = 1 ; i <= len_t ; ++i) {
            dp[i][i - 1] = 0;
            for (int j = i ; j <= len_s ; ++j) {
                if (cstr_t[i - 1] == cstr_s[j - 1])
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
                else
                    dp[i][j] = dp[i][j - 1];
            }
        }

        return dp[len_t][len_s];
    }
};