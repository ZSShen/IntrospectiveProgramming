class Solution {
public:
    /**
     * @param pattern: a string,denote pattern string
     * @param str: a string, denote matching string
     * @return: a boolean
     */
    bool wordPatternMatch(string &pattern, string &str) {
        // write your code here

        std::unordered_map<char, std::string> map;
        std::unordered_set<std::string> dedup;

        return runBackTracking(
            0, pattern.length(), pattern, 0, str.length(), str, map, dedup);
    }

private:
    bool runBackTracking(
            int idx_p,
            int bnd_p,
            const std::string& pat,
            int idx_s,
            int bnd_s,
            const std::string& str,
            std::unordered_map<char, std::string>& map,
            std::unordered_set<std::string>& dedup) {

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

            if (len_t > bnd_s - idx_s) {
                return false;
            }

            auto cand = str.substr(idx_s, len_t);
            if (cand != token) {
                return false;
            }

            auto ret = runBackTracking(
                idx_p + 1, bnd_p, pat, idx_s + len_t, bnd_s, str, map, dedup);
            if (ret) {
                return true;
            }
        } else {
            for (int i = idx_s ; i < bnd_s ; ++i) {
                auto cand = str.substr(idx_s, i - idx_s + 1);

                if (dedup.count(cand) == 1) {
                    continue;
                }

                map[ch] = cand;
                dedup.insert(cand);

                auto ret = runBackTracking(
                    idx_p + 1, bnd_p, pat, i + 1, bnd_s, str, map, dedup);
                if (ret) {
                    return true;
                }

                map.erase(ch);
                dedup.erase(cand);
            }
        }

        return false;
    }
};