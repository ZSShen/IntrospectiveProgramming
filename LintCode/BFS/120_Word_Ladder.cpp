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

        if (start == end) {
            return 1;
        }

        std::queue<std::string> queue;
        queue.push(start);
        int step = 1;

        while (!queue.empty()) {
            int size = queue.size();
            for (int i = 0 ; i < size ; ++i) {
                auto src = queue.front();
                queue.pop();

                int len = src.length();
                for (int j = 0 ; j < len ; ++j) {
                    for (char ch = 'a' ; ch <= 'z' ; ++ch) {
                        std::string dst(src);
                        dst[j] = ch;

                        if (dst == end) {
                            return ++step;
                        }

                        if (dict.count(dst) == 1) {
                            queue.push(dst);
                            dict.erase(dst);
                        }
                    }
                }
            }

            ++step;
        }

        return 0;
    }
};