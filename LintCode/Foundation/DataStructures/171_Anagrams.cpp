class Solution {
public:
    /**
     * @param strs: A list of strings
     * @return: A list of strings
     */
    vector<string> anagrams(vector<string> &strs) {
        // write your code here

        std::unordered_map<std::string, std::vector<std::string>> map;
        for (const auto& str : strs) {
            auto key = str;
            std::sort(key.begin(), key.end());
            map[key].push_back(str);
        }

        std::vector<std::string> ans;
        for (auto& pair : map) {
            if (pair.second.size() > 1) {
                for (auto&& str : pair.second) {
                    ans.push_back(std::move(str));
                }
            }
        }

        return ans;
    }
};