class Solution {
public:
    /*
     * @param words: a set of words without duplicates
     * @return: all word squares
     */
    vector<vector<string>> wordSquares(vector<string> &words) {
        // write your code here

        /**
         *  1. Check the prefix to select candidates.
         *
         *  b a l l
         *  a r e a <= candidate
         *
         *  2. Prefict the prefixes to decide whethere we really should use that
         *     candidate.
         *
         *      | |
         *      $ $
         *  b a l l
         *  a r e a
         */

        if (words.empty()) {
            return {};
        }

        int n = words[0].length();

        std::unordered_map<std::string, std::vector<std::string>> map;
        for (const auto& word : words) {
            map[""].push_back(word);
            for (int i = 1 ; i <= n ; ++i) {
                map[word.substr(0, i)].push_back(word);
            }
        }

        std::vector<std::string> path;
        std::vector<std::vector<std::string>> ans;

        runBacktracking(0, n, map, path, ans);
        return ans;
    }

private:
    void runBacktracking(
            int level, int bound,
            std::unordered_map<std::string, std::vector<std::string>>& map,
            std::vector<std::string>& path,
            std::vector<std::vector<std::string>>& ans) {

        if (level == bound) {
            ans.push_back(path);
            return;
        }

        std::string key;
        for (const auto& cand : path) {
            key += cand[level];
        }

        // Apply the first filtering criterion.
        for (const auto& member : map[key]) {

            path.push_back(member);

            // Apply the second filtering criterion.
            if (isUsable(level + 1, bound, path, map)) {
                runBacktracking(level + 1, bound, map, path, ans);
            }

            path.pop_back();
        }
    }

    bool isUsable(
            int level, int bound,
            std::vector<std::string>& path,
            std::unordered_map<std::string, std::vector<std::string>>& map) {

        for (int i = level ; i < bound ; ++i) {
            std::string key;
            for (const auto& cand : path) {
                key += cand[i];
            }

            if (map.count(key) == 0) {
                return false;
            }
        }

        return true;
    }
};