class Solution {
public:
    Solution()
      : map({
        {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
        {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
        {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
        {"", "M", "MM", "MMM"}
    })
    { }

    /**
     * @param n: The integer
     * @return: Roman representation
     */
    string intToRoman(int n) {
        // write your code here

        return map[3][n / 1000] +
               map[2][(n % 1000) / 100] +
               map[1][(n % 100) / 10] +
               map[0][(n % 10)];
    }

private:
    std::vector<std::vector<std::string>> map;
};