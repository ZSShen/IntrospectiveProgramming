

struct Record {
    std::string word;
    int level;

    Record(const auto& word, int level)
      : word(word), level(level)
    { }
};


class Solution {
public:
    /*
     * @param start: a string
     * @param end: a string
     * @param dict: a set of string
     * @return: An integer
     */
    int ladderLength(string &start, string &end, unordered_set<string> &dict) {
        // write your code here

        /**
         *              dot -- dog
         *            /            \
         *  hit -- hot              cog
         *            \            /
         *              lot -- log
         */

        dict.insert(end);

        std::queue<Record> queue;
        queue.push(Record(start, 1));

        while (!queue.empty()) {

            int n = queue.size();
            for (int i = 0 ; i < n ; ++i) {

                auto front = queue.front();
                queue.pop();
                auto& word = front.word;
                int level = front.level;

                if (word == end) {
                    return level;
                }

                int len = word.length();
                for (int j = 0 ; j < len ; ++j) {

                    char backup = word[j];
                    for (char ch = 'a' ; ch <= 'z' ; ++ch) {
                        word[j] = ch;

                        if(dict.count(word) == 0) {
                            continue;
                        }

                        queue.push(Record(word, level + 1));
                        dict.erase(word);
                    }

                    word[j] = backup;
                }
            }
        }

        return 0;
    }
};