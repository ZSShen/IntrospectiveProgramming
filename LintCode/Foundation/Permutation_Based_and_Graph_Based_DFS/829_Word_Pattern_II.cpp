class Solution {
public:
    /**
     * @param pattern: a string,denote pattern string
     * @param str: a string, denote matching string
     * @return: a boolean
     */
    bool wordPatternMatch(string &pattern, string &str) {
        // write your code here

        int bnd_p = pattern.length();
        if (bnd_p == 0) {
            return false;
        }
        int bnd_s = str.length();
        
        unordered_map<char, std::string> map;
        unordered_set<std::string> set;

        return runBacktracking(0, bnd_p, pattern, 0, bnd_s, str, map, set);
    }
    

private:
    bool runBacktracking(
            int idx_p,
            int bnd_p,
            const std::string& pat,
            int idx_s,
            int bnd_s,
            const std::string& str,
            std::unordered_map<char, std::string>& map,
            std::unordered_set<std::string> set) {
        
        if (idx_p == bnd_p && idx_s == bnd_s) {
            return true;
        }

        if (idx_p == bnd_p || idx_s == bnd_s) {
            return false;
        }

        char ch = pat[idx_p];

        if (map.count(ch) == 1) {
            const auto& token = map[ch];

            int len_t = token.length();
            int space = bnd_s - idx_s;
            if (space < len_t) {
                return false;
            }
            
            if (token != str.substr(idx_s, len_t)) {
                return false;
            }

            bool found = runBacktracking(
                idx_p + 1, bnd_p, pat, idx_s + len_t, bnd_s, str, map, set);
            if (found) {
                return true;
            }

        } else {
            for (int i = idx_s ; i < bnd_s ; ++i) {
                auto token = str.substr(idx_s, i - idx_s + 1);
                if (set.count(token) == 1) {
                    continue;
                }

                map.emplace(ch, token);
                set.emplace(token);

                bool found = runBacktracking(
                    idx_p + 1, bnd_p, pat, i + 1, bnd_s, str, map, set);
                if (found) {
                    return true;
                }

                map.erase(ch);
                set.erase(token);
            }
        }
        
        return false;
    }
};