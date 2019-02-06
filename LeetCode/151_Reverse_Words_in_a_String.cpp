class Solution {
public:
    void reverseWords(string &s) {

        int length = s.length();
        reverseWords(s, 0, length - 1);

        int left = 0, right;
        int copy = 0;
        while (left < length) {
            while (left < length && s[left] == ' ') {
                ++left;
            }

            right = left;
            while (right < length && s[right] != ' ') {
                ++right;
            }
            --right;

            reverseWords(s, left, right);

            // Compress words.
            for (int i = left ; i <= right ; ++i) {
                char ch = s[i];
                s[i] = ' ';
                s[copy++] = ch;
            }
            ++copy;

            left = right + 1;
        }

        while (s.back() == ' ') {
            s.pop_back();
        }
    }

private:
    void reverseWords(string& str, int bgn, int end) {

        while (bgn < end) {
            char ch = str[bgn];
            str[bgn] = str[end];
            str[end] = ch;
            ++bgn;
            --end;
        }
    }
};
