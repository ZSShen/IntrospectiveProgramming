class Solution {
public:
    vector<int> findOrder(int num_course, vector<pair<int, int>>& prereq)
    {
        vector<int> sequence;
        if (num_course == 0)
            return sequence;
        if (num_course == 1) {
            sequence.push_back(0);
            return sequence;
        }

        // Consume the order pairs to create a direct graph.
        vector<list<int>> graph(num_course);
        build_graph(num_course, prereq, graph);

        // Apply topological sort to find the legal sequence.
        vector<char> vec_visited(num_course);
        for (int i = 0 ; i < num_course ; ++i)
            vec_visited[i] = COLOR_WHITE;

        int stamp = num_course;
        vector<int> vec_order(num_course);
        for (int i = 0 ; i < num_course ; ++i) {
            if (vec_visited[i] == COLOR_WHITE) {
                bool no_cycle = topological_sort(vec_visited, vec_order, i,
                                                 graph, &stamp);
                // Detect the cycle. There are some contradict orders.
                if (!no_cycle)
                    return sequence;
            }
        }

        for (int i = 0 ; i < num_course ; ++i) {
            int id_course = vec_order[i];
            sequence.push_back(id_course);
        }

        return sequence;
    }

private:

    enum {
        COLOR_WHITE = 0,
        COLOR_GRAY = 1,
        COLOR_BLACK = 2
    };

    void build_graph(int num_node, vector<pair<int, int>>& prereq, vector<list<int>>& graph)
    {
        for (int i = 0 ; i < num_node ; ++i)
            graph[i] = list<int>();

        for (auto pair : prereq) {
            int src = pair.second;
            int tge = pair.first;
            graph[src].push_back(tge);
        }
    }

    bool topological_sort(vector<char>& vec_visited, vector<int>& vec_order,
        int cur_node, vector<list<int>>& graph, int* p_stamp)
    {
        vec_visited[cur_node] = COLOR_GRAY;
        for (auto next_node : graph[cur_node]) {
            if (vec_visited[next_node] == COLOR_WHITE) {
                bool no_cycle = topological_sort(vec_visited, vec_order, next_node,
                                                 graph, p_stamp);
                // Detect the cycle. There are some contradict orders.
                if (!no_cycle)
                    return false;
            } else if (vec_visited[next_node] == COLOR_GRAY)
                return false;
        }

        int stamp = --*p_stamp;
        vec_order[stamp] = cur_node;
        vec_visited[cur_node] = COLOR_BLACK;
        return true;
    }
};

