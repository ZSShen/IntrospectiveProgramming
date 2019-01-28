class Solution {
public:
    int lengthOfLastWord(string s) {

        int end = s.length() - 1;
        while (end >= 0) {
            if (s[end] != ' ') {
                break;
            }
            --end;
        }

        int bgn = end;
        while (bgn >= 0) {
            if (s[bgn] == ' ') {
                break;
            }
            --bgn;
        }

        return end - bgn;
    }
};