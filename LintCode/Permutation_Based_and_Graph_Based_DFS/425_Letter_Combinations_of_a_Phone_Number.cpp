class Solution {
public:
    /**
     * @param digits: A digital string
     * @return: all posible letter combinations
     */
    vector<string> letterCombinations(string &digits) {
        // write your code here

        std::vector<std::string> ans;
        int len = digits.length();
        if (len == 0) {
            return ans;
        }

        std::unordered_map<int, std::vector<char>> map;
        map[2] = {'a', 'b', 'c'};
        map[3] = {'d', 'e', 'f'};
        map[4] = {'g', 'h', 'i'};
        map[5] = {'j', 'k', 'l'};
        map[6] = {'m', 'n', 'o'};
        map[7] = {'p', 'q', 'r', 's'};
        map[8] = {'t', 'u', 'v'};
        map[9] = {'w', 'x', 'y', 'z'};

        std::vector<std::vector<char>*> levels;

        for (char ch : digits) {
            int index = static_cast<int>(ch - '0');
            levels.push_back(&map[index]);
        }

        std::string prefix;
        runBacktracking(0, len, levels, prefix, ans);
    }

private:
    void runBacktracking(
            int curr,
            int bound,
            std::vector<std::vector<char>*>& levels,
            std::string& prefix,
            std::vector<std::string>& ans) {

        if (curr == bound) {
            ans.push_back(prefix);
            return;
        }

        for (auto ch : *levels[curr]) {
            prefix.push_back(ch);
            runBacktracking(curr + 1, bound, levels, prefix, ans);
            prefix.pop_back();
        }
    }
};