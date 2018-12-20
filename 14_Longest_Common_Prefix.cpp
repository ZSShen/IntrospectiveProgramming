class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        std::string prefix;

        int size = strs.size();
        if (size == 0) {
            return prefix;
        }
        if (size == 1) {
            return strs[0];
        }

        int min_len = 2147483647;
        int str_idx;
        for (int i = 0 ; i < size ; ++i) {
            int len = strs[i].length();
            if (len < min_len) {
                min_len = len;
                str_idx = i;
            }
        }

        if (min_len == 0) {
            return prefix;
        }

        auto model = strs[str_idx];
        strs.erase(strs.begin() + str_idx);
        --size;

        for (int i = 0 ; i < min_len ; ++i) {
            char ch = model[i];

            int j;
            for (j = 0; j < size; ++j) {
                if (ch != strs[j][i]) {
                    break;
                }
            }

            if (j < size) {
                break;
            }

            prefix.push_back(ch);
        }

        return prefix;
    }
};
