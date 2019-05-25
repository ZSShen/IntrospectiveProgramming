class ValidWordAbbr {
public:
    /*
    * @param dictionary: a list of words
    */ValidWordAbbr(vector<string> dictionary) {
        // do intialization if necessary

        for (const auto& word : dictionary) {
            int len = word.length();
            if (len <= 2) {
                continue;
            }
            auto abbr = word[0] + std::to_string(len - 2) + word[len - 1];
            map[abbr].insert(word);
        }
    }

    /*
     * @param word: a string
     * @return: true if its abbreviation is unique or false
     */
    bool isUnique(string &word) {
        // write your code here

        int len = word.length();
        if (len <= 2) {
            return true;
        }

        auto abbr = word[0] + std::to_string(len - 2) + word[len - 1];

        if (map.count(abbr) == 0) {
            return true;
        }
        if (map[abbr].size() > 1) {
            return false;
        }
        return *(map[abbr].begin()) == word;
    }

private:
    std::unordered_map<std::string, std::unordered_set<std::string>> map;
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr obj = new ValidWordAbbr(dictionary);
 * bool param = obj.isUnique(word);
 */