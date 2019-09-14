class Solution {
public:
    /**
     * @param words: word list
     * @param pattern: pattern string
     * @return: list of matching words
     */
    vector<string> findAndReplacePattern(vector<string> &words, string &pattern) {
        // Write your code here.

        std::vector<std::string> ans;
        for (const auto& word : words) {
            if (hasBijection(word, pattern)) {
                ans.push_back(word);
            }
        }

        return ans;
    }

private:
    bool hasBijection(const auto& src, const auto& dst) {

        std::unordered_map<char, char> forward;
        std::unordered_map<char, char> backward;

        int n = src.length();
        for (int i = 0 ; i < n ; ++i) {
            char s = src[i];
            char t = dst[i];

            auto it_f = forward.find(s);
            if (it_f == forward.end()) {
                forward.emplace(std::make_pair(s, t));
            } else {
                if (it_f->second != t) {
                    return false;
                }
            }

            auto it_b = backward.find(t);
            if (it_b == backward.end()) {
                backward.emplace(std::make_pair(t, s));
            } else {
                if (it_b->second != s) {
                    return false;
                }
            }
        }

        return true;
    }
};