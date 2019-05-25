class Solution {
public:
    /**
     * @param num: a string
     * @return: true if a number is strobogrammatic or false
     */
    bool isStrobogrammatic(string &num) {
        // write your code here

        /**
         * Special Digits:
         * 0, 1, 8, 6&9
         */

        std::string mirror;
        for (char ch : num) {
            if (ch == '0') {
                mirror.push_back(ch);
            } else if (ch == '1') {
                mirror.push_back(ch);
            } else if (ch == '8') {
                mirror.push_back(ch);
            } else if (ch == '6') {
                mirror.push_back('9');
            } else if (ch == '9') {
                mirror.push_back('6');
            } else {
                return false;
            }
        }
        std::reverse(mirror.begin(), mirror.end());

        return num == mirror;
    }
};