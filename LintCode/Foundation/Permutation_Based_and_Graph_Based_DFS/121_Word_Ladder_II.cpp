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