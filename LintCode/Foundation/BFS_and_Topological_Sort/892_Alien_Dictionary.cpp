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

        std::unordered_map<char, std::unordered_set<char>> graph;
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

                if (graph.count(ch_src) == 0) {
                    graph[ch_src] = std::unordered_set<char>();
                }
                if (graph.count(ch_dst) == 0) {
                    graph[ch_dst] = std::unordered_set<char>();
                }

                if (ch_src != ch_dst) {
                    graph[ch_src].insert(ch_dst);
                    ++indeg[ch_dst];
                    break;
                }
            }

            while (k < len_src) {
                char ch = src[k++];
                if (graph.count(ch) == 0) {
                    graph[ch] = std::unordered_set<char>();
                }
            }
            while (h < len_dst) {
                char ch = dst[h++];
                if (graph.count(ch) == 0) {
                    graph[ch] = std::unordered_set<char>();
                }
            }
        }

        std::priority_queue<char, std::vector<char>, std::greater<char>> queue;
        for (const auto& pair : graph) {
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

            for (char dst : graph[src]) {
                --indeg[dst];
                if (indeg[dst] == 0) {
                    queue.push(dst);
                }
            }
        }

        return order.length() == graph.size() ? order : "";
    }
};