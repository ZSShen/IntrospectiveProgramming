class Solution {
public:
    int strStr(string haystack, string needle) {

        int len_haystk = haystack.length();
        int len_needle = needle.length();

        if (len_needle == 0) {
            return 0;
        }

        if (len_haystk < len_needle) {
            return -1;
        }

        for (int i = 0 ; i <= len_haystk - len_needle; ++i) {
            int k = 0;
            for (int j = i; k < len_needle ; ++j, ++k) {
                if (haystack[j] != needle[k]) {
                    break;
                }
            }
            if (k == len_needle) {
                return i;
            }
        }

        return -1;
    }
};