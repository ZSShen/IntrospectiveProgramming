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