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

        dict.insert(end);

        std::queue<std::pair<std::string, int>> queue;
        queue.push(std::make_pair(start, 1));

        while (!queue.empty()) {
            auto pair = queue.front();
            queue.pop();

            auto& src = pair.first;
            auto& step = pair.second;

            int size = src.length();
            for (int l = 0 ; l < size ; ++l) {

                std::string dst(src);
                for (char ch = 'a' ; ch <= 'z' ; ++ch) {
                    dst[l] = ch;

                    if (dict.count(dst) == 0) {
                        continue;
                    }

                    if (dst == end) {
                        return step + 1;
                    }

                    queue.push(std::make_pair(dst, step + 1));
                    dict.erase(dst);
                }
            }
        }

        return -1;
    }
};