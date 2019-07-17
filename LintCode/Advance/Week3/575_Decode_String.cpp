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


class Solution {
public:
    /**
     * @param s: an expression includes numbers, letters and brackets
     * @return: a string
     */
    string expressionExpand(string &s) {
        // write your code here

        int bgn = 0;
        return expand(s, bgn, s.length());
    }

private:
    std::string expand(const std::string& str, int& bgn, int end) {

        std::string result;
        std::string time;

        while (bgn < end) {
            char ch = str[bgn];

            if ('a' <= ch && ch <= 'z' ||
                'A' <= ch && ch <= 'Z') {
                result.push_back(ch);

            } else if ('0' <= ch && ch <= '9') {
                time.push_back(ch);

            } else if (ch == '[') {
                ++bgn;

                auto rtn = expand(str, bgn, end);
                int num_time = std::stoi(time);
                for (int i = 0 ; i < num_time ; ++i) {
                    result += rtn;
                }

                // After expanding the returned result by "time" times, we
                // need to reset this counter.
                time = "";

            } else { // ch == ']'
                break;
            }

            ++bgn;
        }

        return result;
    }

};