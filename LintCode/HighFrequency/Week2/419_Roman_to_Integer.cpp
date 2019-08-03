class Solution {
public:
    /**
     * @param s: Roman representation
     * @return: an integer
     */
    int romanToInt(string &s) {
        // write your code here

        int num = 0;
        int len = s.length();
        int i = 0;

        while (i < len) {
            switch(s[i]) {
            case 'I':
                ++i;
                if (s[i] == 'V') {
                    num += 4;
                    ++i;
                } else if (s[i] == 'X') {
                    num += 9;
                    ++i;
                } else {
                    ++num;
                    while (s[i] == 'I') {
                        ++num;
                        ++i;
                    }
                }
                break;

            case 'V':
                num += 5;
                ++i;
                while (s[i] == 'I') {
                    ++num;
                    ++i;
                }
                break;

            case 'X':
                ++i;
                if (s[i] == 'L') {
                    num += 40;
                    ++i;
                } else if (s[i] == 'C') {
                    num += 90;
                    ++i;
                } else {
                    num += 10;
                    while (s[i] == 'X') {
                        num += 10;
                        ++i;
                    }
                }
                break;

            case 'L':
                num += 50;
                ++i;
                while (s[i] == 'X') {
                    num += 10;
                    ++i;
                }
                break;

            case 'C':
                ++i;
                if (s[i] == 'D') {
                    num += 400;
                    ++i;
                } else if (s[i] == 'M') {
                    num += 900;
                    ++i;
                } else {
                    num += 100;
                    while (s[i] == 'C') {
                        num += 100;
                        ++i;
                    }
                }
                break;

            case 'D':
                num += 500;
                ++i;
                while (s[i] == 'C') {
                    num += 100;
                    ++i;
                }
                break;

            case 'M':
                num += 1000;
                ++i;
                while (s[i] == 'M') {
                    num += 1000;
                    ++i;
                }
                break;
            }
        }

        return num;
    }
};


class Solution {
public:
    Solution()
      : map({
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
      })
    { }

    /**
     * @param s: Roman representation
     * @return: an integer
     */
    int romanToInt(string &s) {
        // write your code here

        /**
         * Let's scan the string from the tail to the head.
         *
         * 1. If the value of a Roman character is greater than or etual to  the
         *    value of its predecessor, the accumulative sum is the value of the
         *    predecessor added by the value of the current character.
         *
         *    e.g.: VI = 1 + 5 = 6
         *          VIII = 1 + 1 + 1 + 5 = 8
         *
         * 2. If the value of a Roman character is less than the value of its
         *    predecessor, the accumulative sum is the value of the predecessor
         *    subtracted by the value of the current character.
         *
         *    e.g.: IV = 5 - 1 = 4
         */

        int n = s.length();

        int sum = map[s[n - 1]];

        for (int i = n - 2 ; i >= 0 ; --i) {
            if (map[s[i]] >= map[s[i + 1]]) {
                sum += map[s[i]];
            } else {
                sum -= map[s[i]];
            }
        }

        return sum;
    }

private:
    std::unordered_map<char, int> map;
};