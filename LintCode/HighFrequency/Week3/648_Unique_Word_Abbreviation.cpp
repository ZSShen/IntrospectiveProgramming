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


class ValidWordAbbr {
public:
    /*
    * @param dictionary: a list of words
    */ValidWordAbbr(vector<string> dictionary) {
        // do intialization if necessary

        for (const auto& word: dictionary) {
            auto abbr = genAbbreviation(word);
            ++words[word];
            ++abbrs[abbr];
        }
    }

    /*
     * @param word: a string
     * @return: true if its abbreviation is unique or false
     */
    bool isUnique(string &word) {
        // write your code here

        /**
         * 1. If a word is presented in the word dictionary, it should also be
         *    stored in the abbreviation dictionary. Moreover, the appearance
         *    frequencies of the word and its abbreviation must be equal.
         *
         * 2. On the other hand, if a word is not shown in the word dictionary,
         *    it should not be presented in the abbreviation dictionary, too.
         */

        auto abbr = genAbbreviation(word);
        if (words.count(word) == 1 && abbrs.count(abbr) == 1 &&
            words[word] == abbrs[abbr]) {
            return true;
        }
        if (words.count(word) == 0 && abbrs.count(abbr) == 0) {
            return true;
        }

        return false;
    }


private:
    std::string genAbbreviation(const std::string& str) {

        int len = str.length();
        if (len <= 2) {
            return str;
        }

        return str[0] + std::to_string(len - 2) + str[len - 1];
    }

    std::unordered_map<std::string, int> words;
    std::unordered_map<std::string, int> abbrs;
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr obj = new ValidWordAbbr(dictionary);
 * bool param = obj.isUnique(word);
 */