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
         * dp[i]: The substring ending at index i can be splitted into tokens
         *        which all appear in the dictionary.
         *
         * dp[i] = Bool { dp[k] && dict.has(str.substr(k + 1, j)) }
         *        i<=k<j
         */

        int len = s.length();
        std::vector<bool> dp(len + 1, false);
        dp[0] = true;

        /**
         *  dp[i], enumerate dictionary words
         *
         *  0......i......j
         *
         *  aaa
         *  aa
         *  b
         */

        for (int i = 0 ; i < len ; ++i) {
            if (!dp[i]) {
                continue;
            }

            for (const auto& word : dict) {
                int l = word.length();
                int j = i + l;

                if (j > len || dp[j]) {
                    continue;
                }

                dp[j] = word == s.substr(i, l);
            }
        }

        return dp[len];
    }
};