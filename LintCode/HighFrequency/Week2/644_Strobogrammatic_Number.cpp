class Solution {
public:
    /**
     * @param num: a string
     * @return: true if a number is strobogrammatic or false
     */
    bool isStrobogrammatic(string &num) {
        // write your code here

        std::string mirror;
        for (char ch : num) {
            switch (ch) {
                case '6':
                    mirror.push_back('9');
                    break;
                case '9':
                    mirror.push_back('6');
                    break;
                case '0':
                case '1':
                case '8':
                    mirror.push_back(ch);
                    break;
                default:
                // Simply return false for the numbers including 2, 3, 4, 5, and 7.
                    return false;
            }
        }

        std::reverse(mirror.begin(), mirror.end());
        return mirror == num;
    }
};