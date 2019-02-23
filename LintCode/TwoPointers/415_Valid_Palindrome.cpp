class Solution {
public:
    /**
     * @param s: A string
     * @return: Whether the string is a valid palindrome
     */
    bool isPalindrome(string &s) {
        // write your code here

        int len = s.length();
        if (len <= 1) {
            return true;
        }

        int l = 0, r = len - 1;
        while (l < r) {
            while (l < r && !isAlphanumeric(s[l])) {
                ++l;
            }
            while (l < r && !isAlphanumeric(s[r])) {
                --r;
            }

            char ch_l = (s[l] >= 'a') ? s[l] - 32 : s[l];
            char ch_r = (s[r] >= 'a') ? s[r] - 32 : s[r];
            if (ch_l != ch_r) {
                return false;
            }

            ++l;
            --r;
        }

        return true;
    }

private:
    bool isAlphanumeric(char ch) {

        if (ch >= 'A' && ch <= 'Z') {
            return true;
        }
        if (ch >= 'a' && ch <= 'z') {
            return true;
        }
        if (ch >= '0' && ch <= '9') {
            return true;
        }
        return false;
    }
};