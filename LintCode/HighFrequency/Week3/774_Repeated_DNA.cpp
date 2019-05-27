class Solution {
public:
    /**
     * @param s: a string represent DNA sequences
     * @return: all the 10-letter-long sequences
     */
    vector<string> findRepeatedDna(string &s) {
        // write your code here

        int len = s.length();
        if (len < 10) {
            return {};
        }

        std::unordered_map<std::string, int> map;

        for (int i = 0; i <= len - 10 ; ++i) {
            auto seq = s.substr(i, 10);
            ++map[seq];
        }

        std::vector<std::string> ans;
        for (const auto& pair : map) {
            if (pair.second > 1) {
                ans.push_back(pair.first);
            }
        }

        return ans;
    }
};