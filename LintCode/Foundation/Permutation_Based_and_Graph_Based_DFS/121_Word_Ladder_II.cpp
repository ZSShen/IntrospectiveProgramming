class Solution {
public:
    /*
     * @param start: a string
     * @param end: a string
     * @param dict: a set of string
     * @return: a list of lists of string
     */
    vector<vector<string>> findLadders(string &start, string &end, unordered_set<string> &dict) {
        // write your code here

        /*
            hit -> cog
                               (2) dot - (3) dog
                             /                   \
           (0) hit - (1) hot                       (4) cog
                             \                   /
                               (2) lot - (3) log

        */

        std::unordered_map<std::string, std::unordered_set<std::string>> graph;
        std::unordered_map<std::string, int> discovery;
        buildGraph(start, end, dict, graph, discovery);

        std::vector<std::string> select;
        std::vector<std::vector<std::string>> ans;
        listPaths(0, start, end, graph, discovery, select, ans);

        return ans;
    }

private:
    void buildGraph(
        const std::string& bgn,
        const std::string& end,
        std::unordered_set<std::string>& dict,
        std::unordered_map<std::string, std::unordered_set<std::string>>& graph,
        std::unordered_map<std::string, int>& discovery) {

        dict.insert(end);

        int level = 0;
        discovery[bgn] = level;

        std::queue<std::string> queue;
        queue.push(bgn);

        while (!queue.empty()) {
            int size = queue.size();
            ++level;

            for (int i = 0 ; i < size ; ++i) {
                auto word = queue.front();
                queue.pop();

                std::string cand(word);
                int len = cand.length();
                for (int j = 0 ; j < len ; ++j) {
                    char backup = cand[j];

                    for (char k = 'a' ; k <= 'z' ; ++k) {
                        cand[j] = k;

                        if (dict.count(cand) == 0) {
                            continue;
                        }

                        graph[word].insert(cand);

                        if (discovery.count(cand) == 1) {
                            continue;
                        }

                        discovery[cand] = level;
                        queue.push(cand);
                    }

                    cand[j] = backup;
                }
            }
        }

        dict.erase(end);
    }

    void listPaths(
        int depth,
        const std::string& bgn,
        const std::string& end,
        std::unordered_map<std::string, std::unordered_set<std::string>>& graph,
        std::unordered_map<std::string, int>& discovery,
        std::vector<std::string>& select,
        std::vector<std::vector<std::string>>& ans) {

        select.push_back(bgn);

        if (bgn == end) {
            ans.push_back(select);
        } else {
            for (const auto& neighbor : graph[bgn]) {
                if (discovery[neighbor] != depth + 1) {
                    continue;
                }

                listPaths(
                    depth + 1, neighbor, end, graph, discovery, select, ans);
            }
        }

        select.pop_back();
    }
};


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
     * @return: a list of lists of string
     */
    vector<vector<string>> findLadders(string &start, string &end, unordered_set<string> &dict) {
        // write your code here

        /**
         *                  dot(3) -- dog(4)
         *                /                 \
         * hit(1) - hot(2)                   cog(5)
         *                \                 /
         *                  lot(3) -- log(4)
         *
         */

        std::unordered_map<std::string, std::unordered_set<std::string>> graph;
        std::unordered_map<std::string, int> discover;
        buildGraph(start, end, dict, graph, discover);

        std::vector<std::vector<std::string>> ans;
        std::vector<std::string> collect;
        listPaths(1, start, end, graph, discover, ans, collect);

        return ans;
    }

private:
    void buildGraph(
        const std::string& bgn,
        const std::string& end,
        std::unordered_set<std::string>& dict,
        std::unordered_map<std::string, std::unordered_set<std::string>>& graph,
        std::unordered_map<std::string, int>& discover) {

        dict.insert(end);
        discover[bgn] = 1;

        std::queue<Record> queue;
        queue.push(Record(bgn, 1));

        while (!queue.empty()) {

            int n = queue.size();
            for (int i = 0 ; i < n ; ++i) {

                auto front = queue.front();
                queue.pop();

                auto& src = front.word;
                auto dst(src);
                int level = front.level;

                int len = dst.length();
                for (int j = 0 ; j < len ; ++j) {

                    char backup = dst[j];
                    for (char ch = 'a' ; ch <= 'z' ; ++ch) {
                        dst[j] = ch;

                        if (dict.count(dst) == 0) {
                            continue;
                        }

                        graph[src].insert(dst);

                        if (discover.count(dst) == 1) {
                            continue;
                        }

                        discover[dst] = level + 1;
                        queue.push(Record(dst, level + 1));
                    }

                    dst[j] = backup;
                }
            }
        }
    }


    void listPaths(
        int depth,
        const std::string& bgn,
        const std::string& end,
        std::unordered_map<std::string, std::unordered_set<std::string>>& graph,
        std::unordered_map<std::string, int>& discover,
        std::vector<std::vector<std::string>>& ans,
        std::vector<std::string>& collect) {

        collect.push_back(bgn);

        if (bgn == end) {
            ans.push_back(collect);
        } else {
            for (const auto& nbr : graph[bgn]) {
                if (discover[nbr] != depth + 1) {
                    continue;
                }
                listPaths(depth + 1, nbr, end, graph, discover, ans, collect);
            }
        }

        collect.pop_back();
    }
};