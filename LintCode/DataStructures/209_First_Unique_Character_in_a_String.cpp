#include <list>

class Solution {
public:
    /**
     * @param str: str: the given string
     * @return: char: the first unique character in a given string
     */
    char firstUniqChar(string &str) {
        // Write your code here

        std::list<char> list;
        std::unordered_map<char, std::list<char>::iterator> map;
        std::unordered_set<char> set;

        for (char ch : str) {
            if (set.count(ch) == 1) {
                continue;
            }

            if (map.count(ch) == 0) {
                list.push_back(ch);
                map[ch] = --list.end();
            } else {
                auto& iter = map[ch];
                list.erase(iter);
                map.erase(ch);
                set.insert(ch);
            }
        }

        return list.front();
    }
};