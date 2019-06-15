class Solution {
public:
    /**
     * @param pattern: a string, denote pattern string
     * @param teststr: a string, denote matching string
     * @return: an boolean, denote whether the pattern string and the matching string match or not
     */
    bool wordPattern(string &pattern, string &str) {
        // write your code here

        int len = str.length();
        int bgn = 0, end = 0;

        std::unordered_map<char, std::string> map;
        std::unordered_map<std::string, char> rev;

        for (char ch : pattern) {

            auto token = getToken(str, len, bgn, end);
            if (token.empty()) {
                return false;
            }

            if (map.count(ch) == 0) {
                map[ch] = token;
                rev[token] = ch;
            } else {
                if (map[ch] != token || rev[token] != ch) {
                    return false;
                }
            }
        }

        return true;
    }

private:
    std::string getToken(const std::string& str, int len, int& bgn, int& end) {

        if (end >= len) {
            return "";
        }

        while (end < len && str[end] != ' ') {
            ++end;
        }

        auto token = str.substr(bgn, end - bgn);
        ++end;
        bgn = end;

        return token;
    }
};