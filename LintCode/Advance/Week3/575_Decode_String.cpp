class Solution {
public:
    /**
     * @param s: an expression includes numbers, letters and brackets
     * @return: a string
     */
    string expressionExpand(string &s) {
        // write your code here

        /*
        3[abc2[de]]
        abcdedeabcdedeabcdede
        */
        int bgn = 0;
        return expandExpression(bgn, s.length(), s, 1);
    }

private:
    std::string expandExpression(
            int& bgn,
            int end,
            const std::string& str,
            int times) {

        std::string content;
        std::string new_times;

        while (bgn < end) {
            char ch = str[bgn];

            if (ch == '[') {
                content += expandExpression(++bgn, end, str, std::stoi(new_times));
                new_times.erase();
            } else if (ch == ']') {
                break;
            } else if ('0' <= ch && ch <= '9') {
                new_times += ch;
            } else {
                content += ch;
            }

            ++bgn;
        }

        std::string res;
        for (int i = 0 ; i < times ; ++i) {
            res += content;
        }

        return res;
    }
};