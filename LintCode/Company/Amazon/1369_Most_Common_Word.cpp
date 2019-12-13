class Solution {
public:
    /**
     * @param paragraph:
     * @param banned:
     * @return: nothing
     */
    string mostCommonWord(string &paragraph, vector<string> &banned) {

        std::unordered_set<std::string> black;
        for (const auto& word : banned) {
            black.insert(word);
        }

        // Trim the paragraph.
        for (char& ch : paragraph) {
            if (isalpha(ch)) {
                ch = tolower(ch);
            } else {
                ch = ' ';
            }
        }

        std::unordered_map<std::string, int> freq;
        std::string token;
        std::stringstream stream(paragraph);
        while (std::getline(stream, token, ' ')) {
            if (token.empty() || black.count(token) == 1) {
                continue;
            }
            ++freq[token];
        }

        std::string ans;
        int max = 0;
        for (const auto& pair : freq) {
            if (pair.second > max) {
                max = pair.second;
                ans = pair.first;
            }
        }

        return ans;
    }
};