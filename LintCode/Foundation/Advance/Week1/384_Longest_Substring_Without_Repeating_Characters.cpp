class Solution {
public:
    /**
     * @param s: a string
     * @return: an integer
     */
    int lengthOfLongestSubstring(string &s) {
        // write your code here

        int len = s.size();
        if (len == 0) {
            return 0;
        }

        int l = 0, r = 0;
        int ans = 0;

        std::vector<int> freq(256, 0);

        while (r < len) {

            char ch = s[r];
            ++freq[ch];

            if (freq[ch] == 1) {
                ans = std::max(ans, r - l + 1);
            } else {
                while (freq[ch] == 2) {
                    --freq[s[l]];
                    ++l;
                }
            }

            ++r;
        }

        return ans;
    }
};