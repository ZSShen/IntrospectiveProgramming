class Solution {
public:
    /*
     * @param words: a set of words without duplicates
     * @return: all word squares
     */
    vector<vector<string>> wordSquares(vector<string> &words) {
        // write your code here

        /**
         *  1. To choose a proper candidate in the ith recursion step, we need
         *     to check if there are words starting with the prefix formed by
         *     the first (i - 1) words collected so far.
         *
         *   b a l l
         *   a       => b a l l => the second word should start with "a".
         *   l
         *   l
         *
         *  2. Once we select a legal candidate, we need to predict if we can
         *     find the words starting with the prefix formed by the suffixes
         *     of the i words collected so far in the future round.
         *
         *       * *
         *   b a l l  => b a l l => there must be words starting with "le"
         *   a r e a     a r e a    and "la".
         *   l e
         *   l a
         */

        if (words.empty()) {
            return {};
        }

        int n = words[0].size();

        // Group the words sharing the same prefix.
        std::unordered_map<std::string, std::unordered_set<std::string>> trie;
        for (const auto& word : words) {
            trie[""].insert(word);

            int len = word.length();
            for (int i = 1 ; i <= len ; ++i) {
                auto prefix = word.substr(0, i);
                trie[prefix].insert(word);
            }
        }

        std::vector<std::string> config;
        std::vector<std::vector<std::string>> ans;

        runBackTracking(0, n, trie, config, ans);
        return ans;
    }

private:
    void runBackTracking(
        int index,
        int bound,
        std::unordered_map<std::string, std::unordered_set<std::string>>& trie,
        std::vector<std::string>& config,
        std::vector<std::vector<std::string>>& ans) {

        if (index == bound) {
            ans.push_back(config);
            return;
        }

        // Adopt the 1st filtering criterion.
        std::string key;
        for (const auto& word : config) {
            key += word[index];
        }

        for (const auto& cand : trie[key]) {
            config.push_back(cand);

            // Adopt the 2nd filtering criterion.
            if (canUse(index + 1, bound, trie, config)) {
                runBackTracking(index + 1, bound, trie, config, ans);
            }

            config.pop_back();
        }
    }

    bool canUse(
        int index,
        int bound,
        std::unordered_map<std::string, std::unordered_set<std::string>>& trie,
        std::vector<std::string>& config) {

        for (int i = index ; i < bound ; ++i) {
            std::string key;
            for (const auto& word : config) {
                key += word[i];
            }

            if (trie.count(key) == 0) {
                return false;
            }
        }

        return true;
    }
};