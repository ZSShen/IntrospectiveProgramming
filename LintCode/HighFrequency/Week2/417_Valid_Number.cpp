class Solution {
public:
    bool isNumber(string s) {

        /**
         * Decompose the number format:
         *
         * (): Include the necessary part.
         * []: Include the optional part.
         *
         * [+/-] (Real Number) [Exponent [+/-] (Integer)]
         *                                     *********
         * Once we encounter a exponent symbol, then the remaining integer
         * becomes necessary now.
         *
         * Real Number: abcd
         *              abcd.ef
         *              abce.
         */

        auto str = trim(s);

        int len = str.length();
        int i = 0;
        if (i == len) {
            return false;
        }

        // Patch a dummy white space at the back of the string.
        str.push_back(' ');

        // Check the optional +/- signs.
        if (str[i] == '+' || str[i] == '-') {
            ++i;
        }

        // Check the necessary real number.
        int count_num = 0;
        int count_dot = 0;
        while (('0' <= str[i] && str[i] <= '9') || str[i] == '.') {
            if ('0' <= str[i] && str[i] <= '9') {
                ++count_num;
            }
            if (str[i] == '.') {
                ++count_dot;
            }
            ++i;
        }

        if (count_num == 0 || count_dot > 1) {
            return false;
        }

        // Step into the checking for the optional exponent.
        if (str[i] == 'e') {
            ++i;

            // If we already visit the exponent symbol, the remaining integer
            // now becomes necessary.

            if (str[i] == '+' || str[i] == '-') {
                ++i;
            }

            if (i == len) {
                // 123e
                // 123e+
                // 123e-

                return false;
            }

            // Check the final necessary integer.
            while ('0' <= str[i] && str[i] <= '9') {
                ++i;
            }
        }

        return i == len;
    }

private:
    std::string trim(const std::string& str) {

        // Trim the white spaces before the real number and
        // the white spaces after the integer.

        auto bgn = str.find_first_not_of(' ');
        if (bgn == std::string::npos) {
            return str;
        }

        auto end = str.find_last_not_of(' ');
        if (end == std::string::npos) {
            return str;
        }

        return str.substr(bgn, end - bgn + 1);
    }
};