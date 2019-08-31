#include <list>


class Solution {
public:
    /**
     * @param str: str: the given string
     * @return: char: the first unique character in a given string
     */
    char firstUniqChar(string &str) {
        // Write your code here

        std::unordered_map<char, int> map;
        std::unordered_set<char> set;
        std::list<char> list;

        for (char ch : str) {
            ++map[ch];

            if (set.count(ch) == 0) {
                set.insert(ch);
                list.push_back(ch);
            }

            if (list.front() == ch && map[ch] > 1) {
                list.pop_front();
            }
        }

        return list.front();
    }
};


#include <list>


class Solution {
public:
    /**
     * @param str: str: the given string
     * @return: char: the first unique character in a given string
     */
    char firstUniqChar(string &str) {
        // Write your code here

        std::vector<int> freq(256, 0);

        for (char ch : str) {
            ++freq[ch];
        }

        for (char ch : str) {
            if (freq[ch] == 1) {
                return ch;
            }
        }

        return 0;
    }
};