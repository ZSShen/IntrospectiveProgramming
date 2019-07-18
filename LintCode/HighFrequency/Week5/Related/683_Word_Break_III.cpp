class Solution {
public:
    /*
     * @param : A string
     * @param : A set of word
     * @return: the number of possible sentences.
     */
    int wordBreak3(string& s, unordered_set<string>& words) {
        // Write your code here

        /**
         * dp[i]: The number of ways to decompose the prefix ending at the
         *        ith offset.
         *
         * dp[i] =  SUM { dp[j], if (s.substr(j + 1, i - j) in dict) }
         *         0<=j<i
         *
         * S: 0 ...... i ...... j
         * Suppose we have already calculated the result for dp[i], and then
         * we can extend the current prefix by matching the suffixes with the
         * dictionary words and accumulating the results for dp[j].
         */

        int n = s.length();
        if (n == 0) {
            return 1;
        }

        // We need to handle the words with a case insensitve manner,
        // and thus we generate normalized words before the main routine.
        std::transform(s.begin(), s.end(), s.begin(),
            [](char ch) {
                return std::tolower(ch);
            });

        std::unordered_set<std::string> dict;

        for (const auto& word : words) {
            std::string norm(word);

            std::transform(norm.begin(), norm.end(), norm.begin(),
                [](char ch) {
                    return std::tolower(ch);
                });

            dict.emplace(std::move(norm));
        }

        std::vector<int> dp(n + 1, 0);
        dp[0] = 1;

        for (int i = 0 ; i < n ; ++i) {

            if (dp[i] == 0) {
                continue;
            }

            for (const auto& word : dict) {
                int l = word.length();
                if (l == 0 || i + l > n) {
                    continue;
                }

                if (word == s.substr(i, l)) {
                    dp[i + l] += dp[i];
                }
            }
        }

        return dp[n];
    }
};