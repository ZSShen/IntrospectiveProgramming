class Solution {
public:
    /**
     * @param str: A string
     * @return: An integer
     */
    int atoi(string &str) {
        // write your code here

        int len = str.length();
        int i = 0;

        if (i == len) {
            return 0;
        }

        // Ignore the whitespaces before the first non-whitespace character.
        while (i < len && str[i] == ' ') {
            ++i;
        }

        if (i == len) {
            return 0;
        }

        // Be careful about the case: +-2, which is illegal.
        bool positive = true;
        if (str[i] == '+') {
            ++i;
        } else if (str[i] == '-') {
            positive = false;
            ++i;
        }

        // Process the integral part.
        long sum = 0;
        while (i < len && ('0' <= str[i] && str[i] <= '9')) {
            sum *= 10;
            sum += (str[i] - '0');
            if (sum > INT_MAX) {
                break;
            }
            ++i;
        }

        if (!positive) {
            sum = -sum;
        }

        if (sum > INT_MAX) {
            return INT_MAX;
        }
        if (sum < INT_MIN) {
            return INT_MIN;
        }

        return sum;
    }
};