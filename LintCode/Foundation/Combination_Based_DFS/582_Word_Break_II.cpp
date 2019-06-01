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


class Solution {
public:
    /*
     * @param s: A string
     * @param wordDict: A set of words.
     * @return: All possible sentences.
     */
    vector<string> wordBreak(string &s, unordered_set<string> &wordDict) {
        // write your code here

        std::unordered_map<std::string, std::vector<std::string>> memo;
        return runBacktracking(s, wordDict, memo);
    }

private:
    std::vector<std::string> runBacktracking(
            const std::string& str,
            std::unordered_set<std::string>& dict,
            std::unordered_map<std::string, std::vector<std::string>>& memo) {

        if (memo.count(str) == 1) {
            return memo[str];
        }

        if (str.empty()) {
            return {""};
        }

        std::vector<std::string> combinations;

        int len = str.length();
        for (int i = 1 ; i <= len ; ++i) {
            auto prefix = str.substr(0, i);

            if (dict.count(prefix) == 0) {
                continue;
            }

            auto suffix = str.substr(i, len - i);
            memo[suffix] = runBacktracking(suffix, dict, memo);

            for (const auto& result : memo[suffix]) {
                std::string merge(prefix);
                merge += (result != "") ? " " + result : "";
                combinations.emplace_back(std::move(merge));
            }
        }

        return combinations;
    }
};
