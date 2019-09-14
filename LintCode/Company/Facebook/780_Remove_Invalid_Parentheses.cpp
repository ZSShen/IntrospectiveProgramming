class Solution {
public:
    /**
     * @param s: The input string
     * @return: Return all possible results
     */
    vector<string> removeInvalidParentheses(string &str) {
        // Write your code here

        int l = 0, r = 0;
        for (char ch : str) {
            if (ch == '(') {
                ++l;
            }
            if (ch == ')') {
                if (l > 0) {
                    --l;
                } else {
                    ++r;
                }
            }
        }

        std::vector<std::string> ans;
        runBackTracking(str, 0, str.length(), l, r, ans);
        return ans;
    }

private:
    bool isValid(const auto& str) {

        int count = 0;
        for (char ch : str) {
            if (ch == '(') {
                ++count;
            }
            if (ch == ')') {
                --count;
            }

            if (count < 0) {
                return false;
            }
        }

        return count == 0;
    }

    void runBackTracking(
            const auto& str, int bgn, int end, int l, int r, auto& ans) {

        if (l == 0 && r == 0) {
            if (isValid(str)) {
                ans.push_back(str);
            }
            return;
        }

        for (int i = bgn ; i < end ; ++i) {

            if (!(str[i] == '(' || str[i] == ')')) {
                continue;
            }
            if (i > bgn && str[i] == str[i - 1]) {
                continue;
            }

            if (r > 0 && str[i] == ')') {
                auto copy(str);
                copy.erase(i, 1);
                runBackTracking(copy, i, end - 1, l, r - 1, ans);
            }

            if (l > 0 && str[i] == '(') {
                auto copy(str);
                copy.erase(i, 1);
                runBackTracking(copy, i, end - 1, l - 1, r, ans);
            }
        }
    }
};