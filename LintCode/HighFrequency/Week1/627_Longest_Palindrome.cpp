class Solution {
public:
    /**
     * @param s: a string which consists of lowercase or uppercase letters
     * @return: the length of the longest palindromes that can be built
     */
    int longestPalindrome(string &s) {
        // write your code here

        std::unordered_map<char, int> histogram;
        for (char ch : s) {
            ++histogram[ch];
        }

        int len = 0;
        int odd = 0;
        int compensate = 0;

        for (const auto& pair : histogram) {
            int freq = pair.second;

            if (freq % 2 == 0) {
                len += freq;
            } else {
                len += freq - 1;

                if (freq > odd) {
                    odd = freq;
                    compensate = freq - 1;
                }
            }
        }

        len += odd;
        len -= compensate;

        return len;
    }
};