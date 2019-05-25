class Solution {
public:
    /**
     * @param s: a string
     * @param t: a string
     * @return: true if they are both one edit distance apart or false
     */
    bool isOneEditDistance(string &s, string &t) {
        // write your code here

        int len_s = s.length();
        int len_t = t.length();

        int diff = std::abs(len_s - len_t);
        if (diff > 1) {
            return false;
        }

        if (diff == 1) {
            // Find the common prefix.
            if (len_s < len_t) {
                return checkCommonPrefix(len_s, len_t, s, t);
            } else {
                return checkCommonPrefix(len_t, len_s, t, s);
            }
        }

        int count = 0;
        for (int i = 0 ; i < len_s ; ++i) {
            if (s[i] != t[i]) {
                ++count;
            }

            if (count == 2) {
                break;
            }
        }

        return count == 1;
    }

private:
    bool checkCommonPrefix(
            int len_lhs, int len_rhs,
            const std::string& lhs,
            const std::string& rhs) {

        /**
         * bcde
         * abcde
         *
         * abde
         * abcde
         *
         * abcd
         * abcde
         */

        int i = 0, j = 0;
        while (i < len_lhs && j < len_rhs && lhs[i] == rhs[j]) {
            ++i;
            ++j;
        }

        ++j;
        while (i < len_lhs && j < len_rhs && lhs[i] == rhs[j]) {
            ++i;
            ++j;
        }

        return (i == len_lhs && j == len_rhs);
    }
};
