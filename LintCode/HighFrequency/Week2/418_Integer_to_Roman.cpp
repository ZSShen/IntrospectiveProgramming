class Solution {
public:
    Solution()
      : map({
        {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}, // 1    ~ 9
        {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"}, // 10   ~ 90
        {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"}, // 100  ~ 900
        {"", "M", "MM", "MMM"}                                        // 1000 ~ 3000
      })
    { }

    string intToRoman(int num) {

        return  map[3][num / 1000] +
                map[2][(num % 1000) / 100] +
                map[1][(num % 100) / 10] +
                map[0][num % 10];
    }

private:
    std::vector<std::vector<std::string>> map;
};