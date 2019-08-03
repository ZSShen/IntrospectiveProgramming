class Solution {
public:
    /**
     * @param dict: an array of n distinct non-empty strings
     * @return: an array of minimal possible abbreviations for every word
     */
    vector<string> wordsAbbreviation(vector<string> &dict) {
        // write your code here

        /**
         *   like god internal me internet interval intension face intrusion
         *
         *   l2e  god i6l      me i6t      i6l      i7n       f2e  i7n
         *
         *   l2e  god in5l     me i6t      in5l     in6n      f2e  in6n
         *
         *   l2e  god int4l    me i6t      int4l    int5n     f2e  int5n
         *
         *   l2e  god inte3l   me i6t      inte3l   inte4n    f2e  intr4n
         *
         *   l2e  god inter2l  me i6t      inter2l  inte4n    f2e  intr4n
         *
         *          (no need) => intern1l interv1l
         *
         *           internal              interval
         */

        int n = dict.size();
        if (n == 0) {
            return {};
        }

        std::unordered_map<std::string, int> states;
        std::vector<int> prefix_lens(n);
        std::vector<std::string> ans(n);

        for (int i = 0 ; i < n ; ++i) {
            const auto& word = dict[i];
            prefix_lens[i] = 1;
            auto abbr = genAbbreviation(word, 1);
            ans[i] = abbr;
            ++states[abbr];
        }

        while (true) {
            bool check = true;

            for (int i = 0 ; i < n ; ++i) {
                const auto& word = dict[i];
                const auto& abbr = ans[i];

                if (states[abbr] == 1) {
                    continue;
                }

                // Generate a new abbreviation to differentiate the words
                // mapped to the same abbreviation.
                int prefix_len = ++prefix_lens[i];
                auto new_abbr = genAbbreviation(word, prefix_len);
                ans[i] = new_abbr;
                ++states[new_abbr];
                check = false;
            }

            if (check) {
                break;
            }
        }

        return ans;
    }

private:
    std::string genAbbreviation(const std::string& str, int prefix_len) {

        int len = str.length();
        if (len - 2 <= prefix_len) {
            // internal    prefix len
            // i6l      ->    1
            // intern1l ->    6
            return str;
        }

        return  str.substr(0, prefix_len) +
                std::to_string(len - prefix_len - 1) +
                str[len - 1];
    }
};