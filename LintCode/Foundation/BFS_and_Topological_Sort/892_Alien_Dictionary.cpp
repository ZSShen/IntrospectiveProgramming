class Solution {
public:
    /**
     * @param words: a list of words
     * @return: a string which is correct order
     */
    string alienOrder(vector<string> &words) {
        // Write your code here

        int num = words.size();
        if (num == 0) {
            return "";
        }
        if (num == 1 && words[0].length() == 1) {
            return words[0];
        }

        std::unordered_map<char, std::vector<char>> list;
        std::unordered_map<char, int> indeg;

        for (int i = 1 ; i < num ; ++i) {
            int j = i - 1;
            const auto& src = words[j];
            const auto& dst = words[i];

            int len_src = src.length();
            int len_dst = dst.length();
            int k = 0, h = 0;
            while (k < len_src && h < len_dst) {

                char ch_src = src[k++];
                char ch_dst = dst[h++];

                if (list.count(ch_src) == 0) {
                    list[ch_src] = std::vector<char>();
                }
                if (list.count(ch_dst) == 0) {
                    list[ch_dst] = std::vector<char>();
                }

                if (ch_src != ch_dst) {
                    list[ch_src].push_back(ch_dst);
                    ++indeg[ch_dst];
                    break;
                }
            }

            while (k < len_src) {
                char ch = src[k++];
                if (list.count(ch) == 0) {
                    list[ch] = std::vector<char>();
                }
            }
            while (h < len_dst) {
                char ch = dst[h++];
                if (list.count(ch) == 0) {
                    list[ch] = std::vector<char>();
                }
            }
        }

        std::priority_queue<char, std::vector<char>, std::greater<char>> queue;
        for (const auto& pair : list) {
            char ch = pair.first;
            if (indeg[ch] == 0) {
                queue.push(ch);
            }
        }

        std::string order;

        while (!queue.empty()) {
            char src = queue.top();
            queue.pop();

            order.push_back(src);

            for (char dst : list[src]) {
                --indeg[dst];
                if (indeg[dst] == 0) {
                    queue.push(dst);
                }
            }
        }

        return order.length() == list.size() ? order : "";
    }
};