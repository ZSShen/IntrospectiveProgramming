class Solution {
public:
    /**
     * @param s: the string s
     * @return: the number of operations at least
     */
    int numberOfOperations(string &s) {
        // Write your code here

        int count = 0;

        int l = 0, r = s.length() - 1;
        while (l < r) {
            if (s[l] != s[r]) {
                count += std::abs(s[l] - s[r]);
            }
            ++l;
            --r;
        }

        return count;
    }
};