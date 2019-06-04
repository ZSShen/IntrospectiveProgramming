class Solution {
public:
    /**
     * @param s1: A string
     * @param s2: Another string
     * @return: whether s2 is a scrambled string of s1
     */
    bool isScramble(string &s, string &t) {
        // write your code here

        /**
         * s: s1 + s2
         * t: t1 + t2
         *
         * (s1 == t1 and s2 == t2) or
         * (s1 == t2 and s2 == t1)
         *
         * xyz -> x + yz
         * xyz -> x + yz
         *
         * age -> a + ge
         * gea -> ge + a
         *
         */

        std::unordered_map<
            std::string, std::unordered_map<std::string, bool>> memo;

        return canScramble(s, t, memo);
    }

private:
    bool canScramble(
            const std::string& s,
            const std::string& t,
            std::unordered_map<
                std::string, std::unordered_map<std::string, bool>>& memo) {

        if (memo.count(s) == 1 && memo[s].count(t) == 1) {
            return memo[s][t];
        }

        if (s == t) {
            memo[s][t] = true;
            return true;
        }

        int n = s.length();

        for (int i = 0 ; i < n - 1 ; ++i) {

            int l = i + 1;
            if ((canScramble(s.substr(0, l), t.substr(0, l), memo) &&
                 canScramble(s.substr(l, n - l), t.substr(l, n - l), memo)) ||
                (canScramble(s.substr(0, l), t.substr(n - l, l), memo) &&
                 canScramble(s.substr(l, n - l), t.substr(0, n - l), memo))) {
                return true;
            }
        }

        memo[s][t] = false;
        return false;
    }
};