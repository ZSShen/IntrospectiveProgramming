class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int left = 0;
        int rght = 0;
        int leng = s.length();
        int window = 0;
        int ans = 0;

        char bag[256] = {0};

        while (rght < leng) {
            char ch = s[rght];
            if (!bag[ch]) {
                bag[ch] = true;
                ++rght;

                ++window;
                if (window > ans) {
                    ans = window;
                }

                continue;
            }

            char prev;
            do {
                prev = s[left];
                bag[prev] = false;
                ++left;
                --window;
            } while (prev != ch);
        }

        return ans;
    }
};