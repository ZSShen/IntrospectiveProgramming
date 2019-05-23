class Solution {
public:
    /**
     * @param str: A string
     * @return: An integer
     */
    int atoi(string &str) {
        // write your code here

        auto pos = str.find('.');
        if (pos != std::string::npos) {
            str = str.substr(0, pos);
        }

        int i = 0;
        int len = str.length();

        while (i < len && str[i] == ' ') {
            ++i;
        }

        bool is_positive = true;
        if (str[i] == '+') {
            ++i;
        } else if (str[i] == '-') {
            ++i;
            is_positive = false;
        }

        long long value = 0;
        int max = std::numeric_limits<int>::max();
        int min = std::numeric_limits<int>::min();

        while (i < len) {
            if (str[i] == ' ') {
                ++i;
                continue;
            }
            if (!('0' <= str[i] && str[i] <= '9')) {
                break;
            }

            value *= 10;
            value += str[i] - '0';
            if (value > max) {
                break;
            }

            ++i;
        }

        if (!is_positive) {
            value = -value;
        }

        if (value > max) {
            return max;
        } else if (value < min) {
            return min;
        } else {
            return value;
        }
    }
};