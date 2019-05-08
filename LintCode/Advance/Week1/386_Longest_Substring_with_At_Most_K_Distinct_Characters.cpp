class Solution {
public:
    /**
     * @param s: A string
     * @param k: An integer
     * @return: An integer
     */
    int lengthOfLongestSubstringKDistinct(string &s, int k) {
        // write your code here

        /**
         *     l
         *           r
         *   e c e b a
         *
         *   k = 3
         *   c = 3
         *   window = 4
         *
         *   e: 1
         *   c: 0
         *   b: 1
         *   a: 1
         */

        int len = s.length();
        if (len == 0) {
            return 0;
        }

        std::vector<int> bag(256, 0);

        int l = 0, r = 0;
        int c = 0;
        int opt_size = std::numeric_limits<int>::min();

        while (r < len) {

            char ch = s[r];
            ++bag[ch];

            if (bag[ch] == 1) {
                ++c;
            }

            while (c > k) {
                ch = s[l];
                ++l;

                --bag[ch];
                if (bag[ch] == 0) {
                    --c;
                }

            }

            opt_size = std::max(opt_size, r - l + 1);

            ++r;
        }

        return (opt_size != std::numeric_limits<int>::min()) ? opt_size : len;
    }
};