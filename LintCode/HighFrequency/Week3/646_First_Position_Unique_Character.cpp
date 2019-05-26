class Solution {
public:
    /**
     * @param s: a string
     * @return: it's index
     */
    int firstUniqChar(string &s) {
        // write your code here

        std::unordered_map<char, int> map;
        for (char ch : s) {
            ++map[ch];
        }

        int len = s.length();
        for (int i = 0 ; i < len ; ++i) {
            if (map[s[i]] == 1) {
                return i;
            }
        }

        return -1;
    }
};
