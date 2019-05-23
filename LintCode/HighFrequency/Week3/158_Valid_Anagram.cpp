class Solution {
public:
    /**
     * @param s: The first string
     * @param t: The second string
     * @return: true or false
     */
    bool anagram(string &s, string &t) {
        // write your code here

        int freq_s[256] = {0};
        int freq_t[256] = {0};

        for (char ch : s) {
            ++freq_s[ch];
        }
        for (char ch : t) {
            ++freq_t[ch];
        }

        for (int i = 0 ; i < 256 ; ++i) {
            if (freq_s[i] != freq_t[i]) {
                return false;
            }
        }

        return true;
    }
};