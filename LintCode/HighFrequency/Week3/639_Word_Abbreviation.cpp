class Solution {
public:
    /**
     * @param dict: an array of n distinct non-empty strings
     * @return: an array of minimal possible abbreviations for every word
     */
    vector<string> wordsAbbreviation(vector<string> &dict) {
        // write your code here

        int size = dict.size();

        std::vector<std::string> ans(size);
        std::vector<int> prefixes(size);
        std::unordered_map<std::string, int> stats;

        for (int i = 0 ; i < size ; ++i) {
            prefixes[i] = 1;
            ans[i] = genAbbreviation(dict[i], prefixes[i]);
            ++stats[ans[i]];
        }

        while (true) {
            bool found = false;

            for (int i = 0 ; i < size ; ++i) {
                if (stats[ans[i]] == 1) {
                    continue;
                }

                found = true;
                ++prefixes[i];
                ans[i] = genAbbreviation(dict[i], prefixes[i]);
                ++stats[ans[i]];
            }

            if (!found) {
                break;
            }
        }

        return ans;
    }


private:
    std::string genAbbreviation(const std::string str, int prefix) {

        int len = str.length();
        if (prefix >= len - 2) {
            return str;
        }

        return
            str.substr(0, prefix) +
            std::to_string(len - 1 - prefix) +
            str[len - 1];
    }
};