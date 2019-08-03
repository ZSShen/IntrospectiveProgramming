class Solution {
public:
    Solution()
      : map({
          {'2', {'a', 'b', 'c'}},
          {'3', {'d', 'e', 'f'}},
          {'4', {'g', 'h', 'i'}},
          {'5', {'j', 'k', 'l'}},
          {'6', {'m', 'n', 'o'}},
          {'7', {'p', 'q', 'r', 's'}},
          {'8', {'t', 'u', 'v'}},
          {'9', {'w', 'x', 'y', 'z'}},
      })
    { }

    /**
     * @param digits: A digital string
     * @return: all posible letter combinations
     */
    vector<string> letterCombinations(string &digits) {
        // write your code here

        std::vector<std::string> ans;
        if (digits.empty()) {
            return ans;
        }

        std::string config;
        runBackTracking(0, digits.length(), digits, config, ans);
        return ans;
    }

private:
    void runBackTracking(
            int index, int bound,
            const std::string& digits,
            std::string& config,
            std::vector<std::string>& ans) {

        if (index == bound) {
            ans.push_back(config);
            return;
        }

        char digit = digits[index];
        for (char ch : map[digit]) {
            config.push_back(ch);
            runBackTracking(index + 1, bound, digits, config, ans);
            config.pop_back();
        }
    }

    std::unordered_map<char, std::vector<char>> map;
};