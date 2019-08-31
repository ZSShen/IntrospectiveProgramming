class Solution {
public:
    /**
     * @param word: a non-empty string
     * @param abbr: an abbreviation
     * @return: true if string matches with the given abbr or false
     */
    bool validWordAbbreviation(string &word, string &abbr) {
        // write your code here

        int len_s = word.length();
        int len_t = abbr.length();

        int s = 0, t = 0;
        while (s < len_s && t < len_t) {

            char src = word[s];
            char dst = abbr[t];

            if ('a' <= dst && dst <= 'z') {
                if (src != dst) {
                    break;
                }
                ++s;
                ++t;
            }

            // For the edge case like:
            // word: a
            // abbr: 01
            // 0 hinders the macthcing flow, and thus we should skip this
            // illegal leading digit.

            if (dst == '0') {
                break;
            }

            int num = 0;
            while (t < len_t && ('0' <= dst && dst <= '9')) {
                num *= 10;
                num += dst - '0';

                ++t;
                dst = abbr[t];
            }

            s += num;
        }

        return (s == len_s) && (t == len_t);
    }
};


class Solution {
public:
    /**
     * @param word: a non-empty string
     * @param abbr: an abbreviation
     * @return: true if string matches with the given abbr or false
     */
    bool validWordAbbreviation(string &word, string &abbr) {
        // write your code here

        int len_w = word.length();
        int len_a = abbr.length();

        int index_w = 0, index_a = 0;
        while (index_w < len_w && index_a < len_a) {

            if ('0' <= abbr[index_a] && abbr[index_a] <= '9') {

                if (abbr[index_a] == '0') {
                    break;
                }

                int num = 0;
                while ('0' <= abbr[index_a] && abbr[index_a] <= '9') {
                    num *= 10;
                    num += (abbr[index_a] - '0');
                    ++index_a;
                }

                index_w += num;
                continue;
            }

            if (abbr[index_a] != word[index_w]) {
                break;
            }

            ++index_w;
            ++index_a;
        }

        return (index_w == len_w) && (index_a == len_a);
    }
};