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

        int len = s.length();
        int num = map[s[len - 1]];

        for (int i = len - 2 ; i >= 0 ; --i) {
            if (map[s[i]] >= map[s[i + 1]]) {
                num += map[s[i]];
            } else {
                num -= map[s[i]];
            }
        }

        return num;
    }

private:
    std::unordered_map<char, int> map;
};