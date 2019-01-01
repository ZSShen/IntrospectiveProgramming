class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        std::unordered_map<std::string, std::vector<std::string>> groups;

        for (auto& str : strs) {
            auto key(str);
            std::sort(key.begin(), key.end());
            groups[key].push_back(str);
        }

        std::vector<std::vector<std::string>> ans;
        for (auto& pair : groups) {
            ans.push_back(std::move(pair.second));
        }

        return ans;
    }
};