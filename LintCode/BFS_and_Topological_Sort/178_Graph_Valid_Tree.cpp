class Solution {
public:
    /**
     * @param n: An integer
     * @param edges: a list of undirected edges
     * @return: true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>> &edges) {
        // write your code here

        if (n == 0) {
            return false;
        }

        if (edges.size() != n - 1) {
            return false;
        }

        std::vector<std::vector<int>> graph(n, std::vector<int>());
        for (const auto& edge : edges) {
            int src = edge[0];
            int dst = edge[1];
            graph[src].push_back(dst);
            graph[dst].push_back(src);
        }

        std::unordered_set<int> visit;
        std::queue<int> queue;

        queue.push(0);
        visit.insert(0);

        while (!queue.empty()) {
            auto curr = queue.front();
            queue.pop();

            for (auto neighbor : graph[curr]) {
                if (visit.count(neighbor) == 0) {
                    queue.push(neighbor);
                    visit.insert(neighbor);
                }
            }
        }

        return visit.size() == n;
    }
};