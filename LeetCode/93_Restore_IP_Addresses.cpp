class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        std::vector<std::string> ans;
        int length = s.length();
        if (length < 4) {
            return ans;
        }
        if (length > 12) {
            return ans;
        }

        std::vector<std::pair<const char*, int>> collect;
        backtrack(0, s.length(), s.c_str(), 0, collect, ans);
        return ans;
    }

private:
    void backtrack(int bgn, int end, const char* str, int level, 
            std::vector<std::pair<const char*, int>>& collect, 
            std::vector<std::string>& ans) {
    
        if (level == 4) { 
            if (bgn == end) {
                char ip[16] = {0};
                int pivot = 0;
                for (const auto& pair : collect) {
                    for (int i = 0 ; i < pair.second ; ++i) {
                        ip[pivot++] = pair.first[i];
                    }
                    ip[pivot++] = '.';
                }
                ip[--pivot] = 0;
                ans.push_back(ip);      
            }
            return;
        }            
        
        // Tackle single digit.
        collect.push_back(std::make_pair(str + bgn, 1));
        backtrack(bgn + 1, end, str, level + 1, collect, ans);
        collect.pop_back();

        if (str[bgn] == '0') {
            return;
        }
        if (bgn == end - 1) {
            return;
        }

        // Tackle double digits.
        collect.push_back(std::make_pair(str + bgn, 2));
        backtrack(bgn + 2, end, str, level + 1, collect, ans);
        collect.pop_back();

        if (bgn == end - 2) {
            return;
        }        

        // Tackle triple digits.
        char num[4];
        num[0] = str[bgn];
        num[1] = str[bgn + 1];
        num[2] = str[bgn + 2];
        num[3] = 0;

        if (atoi(num) > 255) {
            return;
        }        

        collect.push_back(std::make_pair(str + bgn, 3));
        backtrack(bgn + 3, end, str, level + 1, collect, ans);
        collect.pop_back();
    }
};