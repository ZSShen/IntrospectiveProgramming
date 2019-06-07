class Solution {
public:
    /**
     * @param words: a list of unique words
     * @return: all pairs of distinct indices
     */
    vector<vector<int>> palindromePairs(vector<string> &words) {
        // Write your code here

        /**
         * 1. "abcba" + "", "" + "abcba"
         *
         * 2. "abc" + "cba" => "abccba"
         *
         * 3. "acbdb" => "ac", "bdb", "ca" => "acbdbca"
         *
         * 4. "bdbac" => "ca", "bdb", "ac" => "cabdbac"
         *
         * O(n * k^2)
         */

        int n = words.size();
        if (n < 2) {
            return {};
        }

        std::unordered_map<std::string, int> map;
        std::vector<int> empty;

        for (int i = 0 ; i < n ; ++i) {
            const auto& word = words[i];

            if (word.empty()) {
                empty.push_back(i);
                continue;
            }

            auto rev(word);
            std::reverse(rev.begin(), rev.end());
            map[rev] = i;
        }

        std::vector<std::vector<int>> ans;

        for (int i = 0 ; i < n ; ++i) {
            const auto& word = words[i];

            // Case 1.
            // "abcba" + ""
            if (isPalin(word)) {
                for (int j : empty) {
                    if (i == j) {
                        continue;
                    }
                    ans.push_back({i, j});
                    ans.push_back({j, i});
                }
            }

            // Case 2.
            // "abc" + "cba"
            if (map.count(word) != 0 && map[word] != i) {
                ans.push_back({i, map[word]});
            }

            // Case 3 and Case 4.
            // "ca" + "bdbac"
            // "acbdb" + "ca"
            int len = word.length();
            for (int j = 1 ; j < len ; ++j) {
                auto left = word.substr(0, j);
                auto rght = word.substr(j, len - j);

                if (isPalin(left) && map.count(rght) != 0 && map[rght] != i) {
                    ans.push_back({map[rght], i});
                }

                if (isPalin(rght) && map.count(left) != 0 && map[left] != i) {
                    ans.push_back({i, map[left]});
                }
            }
        }

        return ans;
    }


private:
    bool isPalin(const std::string& str) {
        int l = 0;
        int r = str.length() - 1;

        while (l < r) {
            if (str[l] != str[r]) {
                return false;
            }
            ++l;
            --r;
        }

        return true;
    }
};