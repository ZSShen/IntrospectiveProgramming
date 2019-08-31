class Solution {
public:
    /**
     * @param s: A string
     * @param p: A string includes "." and "*"
     * @return: A boolean
     */
    bool isMatch(string &s, string &p) {
        // write your code here

        int bnd_s = s.length();
        int bnd_p = p.length();

        std::vector<std::vector<bool>>
            visit(bnd_s, std::vector<bool>(bnd_p, false));
        std::vector<std::vector<bool>>
            memo(bnd_s, std::vector<bool>(bnd_p, false));

        return matchRE(0, bnd_s, 0, bnd_p, s, p, visit, memo);
    }

private:
    bool matchRE(
            int idx_s,
            int bnd_s,
            int idx_p,
            int bnd_p,
            const std::string& s,
            const std::string& p,
            std::vector<std::vector<bool>>& visit,
            std::vector<std::vector<bool>>& memo) {

        if (idx_p == bnd_p) {
            return idx_s == bnd_s;
        }

        if (idx_s == bnd_s) {
            return isEmpty(idx_p, bnd_p, p);
        }

        if (visit[idx_s][idx_p]) {
            return memo[idx_s][idx_p];
        }

        bool match;
        if (idx_p + 1 < bnd_p && p[idx_p + 1] == '*') {
            match =
                // Match S with *.
                matchChar(s[idx_s], p[idx_p]) &&
                matchRE(idx_s + 1, bnd_s, idx_p, bnd_p, s, p, visit, memo) ||
                // Do not Match S.
                matchRE(idx_s, bnd_s, idx_p + 2, bnd_p, s, p, visit, memo);

        } else {
            match =
                matchChar(s[idx_s], p[idx_p]) &&
                matchRE(idx_s + 1, bnd_s, idx_p + 1, bnd_p, s, p, visit, memo);
        }

        visit[idx_s][idx_p] = true;
        memo[idx_s][idx_p] = match;

        return match;
    }


    bool matchChar(char ch_s, char ch_p) {
        return ch_p == '.' || ch_s == ch_p;
    }

    bool isEmpty(int idx_p, int bnd_p, const std::string& p) {
        // a*b*c*
        for (int i = idx_p ; i < bnd_p ; i += 2) {
            if (i + 1 >= bnd_p || p[idx_p + 1] != '*') {
                return false;
            }
        }

        return true;
    }
};


class Solution {
public:
    /**
     * @param s: A string
     * @param p: A string includes "." and "*"
     * @return: A boolean
     */
    bool isMatch(string &s, string &p) {
        // write your code here

        /**
         * dp[i][j]: Whether the substring of s ending at the index i can be
         *           matched by the subpattern of p ending at the index j.
         *
         *            | if s[i] == p[j] || p[j] == '.'        , dp[i - 1][j - 1]
         *            |
         * dp[i][j] = | if p[j] == '*'
         *            | |  s[i] == p[j - 1] || p[j - 1] == '.', dp[i - 1][j]
         *            | |  No plan to match                   , dp[i][j - 2]
         *            |
         *            | Otherwise                             , false
         */

        int len_s = s.length();
        int len_p = p.length();

        std::vector<std::vector<bool>>
            dp(len_s + 1, std::vector<bool>(len_p + 1, false));
        dp[0][0] = true;

        for (int i = 1 ; i <= len_p ; ++i) {
            if (i >= 2 && p[i - 1] == '*') {
                dp[0][i] = dp[0][i - 2];
            }
        }

        for (int i = 1 ; i <= len_s ; ++i) {
            for (int j = 1 ; j <= len_p ; ++j) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                if (j >= 2 && p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2];
                    if (s[i - 1] == p[j - 2] || p[j - 2] == '.') {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                }
            }
        }

        return dp[len_s][len_p];
    }
};