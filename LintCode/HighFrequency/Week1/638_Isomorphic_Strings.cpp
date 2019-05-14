class Solution {
public:
    /**
     * @param s: a string
     * @param t: a string
     * @return: true if the characters in s can be replaced to get t or false
     */
    bool isIsomorphic(string &s, string &t) {
        // write your code here

        /**
         *  add  ade  add
         *  egg  egg  egd
         */

        int len_s = s.length();
        int len_t = t.length();
        if (len_s != len_t) {
            return false;
        }

        char map[256] = {0};
        bool use[256] = {false};

        for (int i = 0 ; i < len_s ; ++i) {
            char src = s[i];
            char dst = t[i];

            if (map[src] == 0) {
                if (use[dst]) {
                    return false;
                }
                map[src] = dst;
                use[dst] = true;
            } else {
                if (map[src] != dst) {
                    return false;
                }
            }
        }

        return true;
    }
};