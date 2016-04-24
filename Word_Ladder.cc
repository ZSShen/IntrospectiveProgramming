class Solution {
public:
    int ladderLength(string word_bgn, string word_end, unordered_set<string>& set_word)
    {
        int count_node = set_word.size() + 2;
        vector<vector<int>> graph(count_node);
        bool no_early_quit = build_graph(count_node, graph, word_bgn, word_end, set_word);
        if (!no_early_quit)
            return 0;

        int count_step = breadth_first_search(count_node, graph);
        return count_step;
    }

private:
    bool build_graph(int count_node, vector<vector<int>>& graph,
            string& word_bgn, string& word_end, unordered_set<string>& set_word)
    {
        for (int i = 0 ; i < count_node ; ++i)
            graph[i] = vector<int>();

        int len_word = word_bgn.length();

        // Build the linkage between:
        //      beginning word and dictionary words.
        //      ending word and dictionary words.
        int id_bgn = 0;
        int id_end = count_node - 1;
        const char* cstr_bgn = word_bgn.c_str();
        const char* cstr_end = word_end.c_str();

        int id = 1;
        for (auto word : set_word) {
            const char* cstr = word.c_str();
            bool is_linked = determine_linkage(cstr_bgn, cstr, len_word);
            if (is_linked)
                graph[id_bgn].push_back(id);

            is_linked = determine_linkage(cstr_end, cstr, len_word);
            if (is_linked) {
                graph[id].push_back(id_end);
                graph[id_end].push_back(id);
            }
            ++id;
        }

        if (graph[id_bgn].size() == 0 ||
            graph[id_end].size() == 0)
            return false;

        // Build the linkage between dictionary words.
        int id_src = 1;
        for (auto word_src : set_word) {
            int id_tge = 1;
            for (auto word_tge : set_word) {
                if (id_src == id_tge)
                    continue;

                // Only the word pair with distance "1" can be considered as linked.
                const char* cstr_src = word_src.c_str();
                const char* cstr_tge = word_tge.c_str();
                bool is_linked = determine_linkage(cstr_src, cstr_tge, len_word);
                if (is_linked) {
                    graph[id_src].push_back(id_tge);
                    graph[id_tge].push_back(id_src);
                }
                ++id_tge;
            }
            ++id_src;
        }
        return true;
    }

    bool determine_linkage(const char* cstr_src, const char* cstr_tge, int len_word)
    {
        int distance = 0;
        bool is_linked = false;
        for (int i = 0 ; i < len_word ; ++i) {
            if (cstr_src[i] != cstr_tge[i]) {
                ++distance;
                if (distance == 1)
                    is_linked = true;
                else {
                    is_linked = false;
                    break;
                }
            }
        }
        return is_linked;
    }

    int breadth_first_search(int count_node, vector<vector<int>>& graph)
    {
        vector<bool> vec_visited(count_node);
        for (int i = 0 ; i < count_node ; ++i)
            vec_visited[i] = false;

        int id_bgn = 0;
        int id_end = count_node - 1;
        queue<pair<int, int>> progress;
        progress.push(make_pair(id_bgn, 1));
        while (!progress.empty()) {
            auto curr = progress.front();
            int id_src = curr.first;
            int count_step = curr.second;
            progress.pop();
            vec_visited[id_src] = true;

            for (auto id_tge : graph[id_src]) {
                if (!vec_visited[id_tge]) {
                    if (id_tge == id_end)
                        return count_step + 1;
                    progress.push(make_pair(id_tge, count_step + 1));
                }
            }
        }

        return 0;
    }
};