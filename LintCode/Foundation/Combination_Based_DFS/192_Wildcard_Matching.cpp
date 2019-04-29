class Solution {
public:
    /**
     * @param s: A string
     * @param p: A string includes "?" and "*"
     * @return: is Match?
     */
    bool isMatch(string &s, string &p) {
        // write your code here

        int size_s = s.length();
        int size_p = p.length();

        std::vector<std::vector<bool>> visit(
                size_s, std::vector<bool>(size_p, false));
        std::vector<std::vector<bool>> memo(
                size_s, std::vector<bool>(size_p, false));

        return runBacktracking(0, size_s, s, 0, size_p, p, visit, memo);
    }

private:
    bool runBacktracking(
            int index_s,
            int size_s,
            const std::string& s,
            int index_p,
            int size_p,
            const std::string& p,
            std::vector<std::vector<bool>>& visit,
            std::vector<std::vector<bool>>& memo) {

        if (index_p == size_p) {
            return index_s == size_s;
        }

        if (index_s == size_s) {
            bool check = true;
            for (int i = index_p ; i < size_p ; ++i) {
                if (p[i] != '*') {
                    check = false;
                    break;
                }
            }
            return check;
        }

        if (visit[index_s][index_p]) {
            return memo[index_s][index_p];
        }

        char char_s = s[index_s];
        char char_p = p[index_p];
        bool match;

        if (char_p == '*') {
            match = runBacktracking(
                        index_s, size_s, s, index_p + 1, size_p, p,
                        visit, memo) ||
                    runBacktracking(
                        index_s + 1, size_s, s, index_p, size_p, p,
                        visit, memo);
        } else {
            match = ((char_p == '?') ? true : char_s == char_p) &&
                    runBacktracking(
                        index_s + 1, size_s, s, index_p + 1, size_p, p,
                        visit, memo);
        }

        visit[index_s][index_p] = true;
        memo[index_s][index_p] = match;
        return match;
    }
};


class DpSolution {
public:
    /**
     * @param s: A string 
     * @param p: A string includes "?" and "*"
     * @return: is Match?
     */
    bool isMatch(string &s, string &p) {
        // write your code here
        
        /**
         *  s: abcde
         *  p: a*b?e
         * 
         *             | dp[i - 1][j - 1]             , if s[i] == p[j] || p[j] == '?'
         *  dp[i][j] = | dp[i - 1][j] || dp[i][j - 1] , if p[j] == '*'
         *             | false
         */
        
        int len_s = s.length();
        int len_p = p.length();

        bool dp[len_s + 1][len_p + 1] = {};
        dp[0][0] = true;

        for (int i = 1 ; i <= len_p ; ++i) {
            if (p[i - 1] != '*') {
                break;
            }
            dp[0][i] = true;
        }

        for (int i = 1 ; i <= len_s ; ++i) {
            for (int j = 1 ; j <= len_p ; ++j) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
            }
        }
        
        return dp[len_s][len_p];
    }
};


class DpSolution {
public:
    bool isMatch(string s, string p) {
        
        /**
         *
         * s: abcde
         * p: ab*cd*e
         *
         *            | dp[i - 1][j - 1] , if s[i] == p[j] || p[j] == '.'
         * dp[i][j] = |                  , if p[j] == '*'
         *                  | dp[i][j - 2]  , Do not use * to match S.
         * .                | dp[i - 1][j]  , s[i] == p[j - 1] || p[j - 1] == '.'
         *            | false
         * 
         */
        
        int len_s = s.length();
        int len_p = p.length();
        
        bool dp[len_s + 1][len_p + 1] = {};
        dp[0][0] = true;
        
        // special case.
        // s: ""
        // p: a*b*c*
        for (int i = 1 ; i <= len_p ; i += 2) {
            if (i + 1 > len_p || p[i] != '*') {
                break;
            }
            dp[0][i + 1] = true;
        }
        
        for (int i = 1 ; i <= len_s ; ++i) {
            for (int j = 1 ; j <= len_p ; ++j) {

                if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];

                } else if (p[j - 1] == '*') {
                    // Do not match.
                    dp[i][j] = dp[i][j - 2]; 
                    
                    // Try to use * to match S.
                    if (s[i - 1] == p[j - 2] || p[j - 2] == '.') {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                }
            }
        }
        
        return dp[len_s][len_p];
    }
};