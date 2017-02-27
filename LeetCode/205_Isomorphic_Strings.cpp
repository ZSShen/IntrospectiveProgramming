class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int len = s.length();
        if (len == 0) {
            return true;
        }

        char map[256] = {0};
        bool used[256] = {false};

        for (int i = 0 ; i < len ; ++i) {
            char chS = s[i];
            char chT = t[i];

            if (map[chS] == 0) {
                if (used[chT] == true) {
                    return false;
                }
                map[chS] = chT;
                used[chT] = true;
                continue;
            }

            if (map[chS] != chT) {
                return false;
            }
        }

        return true;
    }
};