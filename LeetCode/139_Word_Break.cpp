class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        int len = s.length();

        bool dp[len + 1] = {false};
        dp[0] = true;

        std::unordered_set<std::string> dict;
        for (const auto& word : wordDict) {
            dict.insert(word);
        }

        for (int i = 1 ; i <= len ; ++i) {
            for (int j = 0 ; j < i ; ++j) {
                bool match = dp[j] && dict.count(s.substr(j, i - j)) == 1;
                if (match) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[len];
    }
};