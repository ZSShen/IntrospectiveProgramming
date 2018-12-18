class Solution {
public:
    string longestPalindrome(string s) {

        auto len = s.length();
        if (len < 2) {
            return s;
        }

        /**
         * Formula:
         * isPalin[i][j] = | false, if str[i] != str[j]
         *                 | false, if str[i] == str[j] and isPalin[i][j] == false
         *                 | true,  if str[i] == str[j] and isPalin[i][j] == true
         */

        std::vector<std::vector<bool>> isPalin(len);
        for (int i = 0 ; i < len ; ++i) {
            isPalin[i].resize(len);
            isPalin[i][i] = true;
        }

        int start = 0;
        int window = 1;

        for (int i = 0, j = 1 ; i < len - 1 ; ++i, ++j) {
            if (s[i] == s[j]) {
                isPalin[i][j] = true;
                start = i;
                window = 2;
            }
        }

        for (int l = 2 ; l < len ; ++l) {
            for (int i = 0, j = i + l; j < len ; ++i, ++j) {
                if (s[i] != s[j]) {
                    continue;
                }
                if (!isPalin[i + 1][j - 1]) {
                    continue;
                }

                isPalin[i][j] = true;
                start = i;
                window = l + 1;
            }
        }

        return s.substr(start, window);
    }
};