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