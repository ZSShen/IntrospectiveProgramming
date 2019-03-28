class Solution {
public:
    /*
     * @param s: A string
     * @param wordDict: A set of words.
     * @return: All possible sentences.
     */
    vector<string> wordBreak(string &s, unordered_set<string> &wordDict) {
        // write your code here

        std::unordered_map<std::string, std::vector<std::string>> map;
        return runBacktracking(s, wordDict, map);
    }


private:
    std::vector<std::string> runBacktracking(
            const std::string& str,
            const std::unordered_set<std::string>& dict,
            std::unordered_map<std::string, std::vector<std::string>>& map) {

        if (map.count(str) == 1) {
            return map[str];
        }

        if (str.empty()) {
            return {""};
        }

        std::vector<std::string> collect;
        int len_str = str.length();

        for (const auto& word : dict) {

            int len_word = word.length();
            if (len_word == 0) {
                continue;
            }
            if (len_word > len_str) {
                continue;
            }
            if (str.substr(0, len_word) != word) {
                continue;
            }

            auto suffix = str.substr(len_word);
            map[suffix] = runBacktracking(suffix, dict, map);
            for (const auto& piece : map[suffix]) {
                collect.push_back(word + (piece.empty() ? "" : " " + piece));
            }
        }

        return collect;
    }
};