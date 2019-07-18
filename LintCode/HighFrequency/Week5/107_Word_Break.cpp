class Solution {
public:
    /*
     * @param s: A string
     * @param dict: A dictionary of words dict
     * @return: A boolean
     */
    bool wordBreak(string &s, unordered_set<string> &dict) {
        // write your code here

        /**
         * dp[i]: Whether the prefix ending at the ith position can be composed
         *        by the dictionary words.
         *
         * dp[i] =   OR { dp[j] && (s.substr(j + 1, i) in dict) }
         *         0<=j<i
         *
         * Denote n as the length of s, and then the time complexity of this
         * baseline approach is O(n^2).
         *
         * In real implementation, we can further boost the performance by
         * enumerating the dictionary words in the inner loop. Suppose that
         * we have k words in total, and then the complexity of this approach
         * is O(nk).
         *
         * S: 0 ...... i ......j
         * we have already calcuated the result for dp[i], and we enumerate
         * the dictionary words to predict the result for dp[j], where j > i.
         *
         */

        /*
        int n = s.length();
        if (n == 0) {
            return true;
        }

        std::vector<bool> dp(n + 1, false);
        dp[0] = true;

        for (int i = 1 ; i <= n ; ++i) {
            bool match = false;
            for (int j = 0 ; j < i ; ++j) {
                match = dp[j] && dict.count(s.substr(j, i - j)) == 1;
                if (match) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
        */

        int n = s.length();
        if (n == 0) {
            return true;
        }

        std::vector<bool> dp(n + 1, false);
        dp[0] = true;

        for (int i = 0 ; i < n ; ++i) {
            if (!dp[i]) {
                continue;
            }

            for (const auto& word : dict) {
                int len = word.length();
                int j = i + len;

                if (len == 0 || j > n || dp[j]) {
                    continue;
                }

                dp[j] = word == s.substr(i, len);
            }
        }

        return dp[n];
    }
};