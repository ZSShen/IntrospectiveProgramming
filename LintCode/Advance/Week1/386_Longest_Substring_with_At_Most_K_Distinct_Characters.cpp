class Solution {
public:
    /**
     * @param s: A string
     * @param k: An integer
     * @return: An integer
     */
    int lengthOfLongestSubstringKDistinct(string &s, int k) {
        // write your code here

        int n = s.length();
        if (n == 0) {
            return 0;
        }

        std::vector<int> bag(256, 0);
        int l = 0, r = 0;
        int count = 0;
        int ans = 0;

        while (r < n) {

            char ch = s[r];
            ++bag[ch];

            if (bag[ch] == 1) {
                ++count;
            }

            if (count <= k) {
                // Update the window size here.
                ans = std::max(ans, r - l + 1);
            } else {
                while (count > k) {
                    ch = s[l];

                    --bag[ch];
                    if (bag[ch] == 0) {
                        --count;
                    }

                    ++l;
                }
            }

            ++r;
        }

        return ans;
    }
};