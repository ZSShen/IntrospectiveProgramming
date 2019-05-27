class Solution {
public:
    /**
     * @param strs: the given array of strings
     * @return: The anagrams which have been divided into groups
     */
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        // write your code here

        int size = strs.size();
        if (size == 0) {
            return {};
        }

        std::unordered_map<std::string, std::vector<std::string>> groups;

        for (const auto& word :strs) {
            auto key(word);
            std::sort(key.begin(), key.end());
            groups[key].push_back(word);
        }

        std::vector<std::vector<std::string>> ans;
        for (auto& pair : groups) {
            ans.push_back(std::move(pair.second));
        }

        return ans;
    }
};