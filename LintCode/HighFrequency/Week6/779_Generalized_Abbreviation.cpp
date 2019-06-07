class Solution {
public:
    /**
     * @param word: the given word
     * @return: the generalized abbreviations of a word
     */
    vector<string> generateAbbreviations(string &word) {
        // Write your code here

        /**
         *  w o r d
         *
         *  1: 1ord, w1rd, wo1d, wor1
         *  2: 2rd, w2d, ...
         *  3: 3d, ...
         *  4: 4
         *
         *  1ord -> 2rd -> 3d -> 4
         *              -> 2r1
         *       -> 1o1d -> 1o2
         *
         *  w1rd -> w2d -> w3
         *
         *       -> w1r1
         *
         *  wo1d -> wo2
         *
         *  wor1
         */

        std::unordered_set<std::string> collect;
        collect.insert(word);
        runBacktracking(1, word.length(), 0, word, collect);

        std::vector<std::string> ans;
        for (auto&& word : collect) {
            ans.emplace_back(word);
        }

        return ans;
    }

private:
    void runBacktracking(
            int level, int bound,
            int offset,
            std::string& word,
            std::unordered_set<std::string>& collect) {

        if (level > bound || offset >= bound) {
            return;
        }

        int skip = std::log10(level) + 1;
        for (int i = offset ; i <= bound - level ; ++i) {

            auto abbr = word.substr(0, i) +
                        std::to_string(level) +
                        word.substr(i + level, bound - level);

            if (collect.count(abbr) == 1) {
                break;
            }
            collect.insert(abbr);
            runBacktracking(level + 1, bound, i, word, collect);
            runBacktracking(1, abbr.length(), i + skip + 1, abbr, collect);
        }
    }
};