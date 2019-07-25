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


class DisjointSet {

public:
    DisjointSet(int n)
      : parents(std::vector<int>(n)) {

        for (int i = 0 ; i < n ; ++i) {
            parents[i] = i;
        }
    }

    int find(int x) {

        if (parents[x] == x) {
            return x;
        }

        parents[x] = find(parents[x]);
        return parents[x];
    }

    bool merge(int x, int y) {

        int px = find(x);
        int py = find(y);

        if (px != py) {
            parents[px] = py;
            return true;
        }

        return false;
    }


private:
    std::vector<int> parents;
};


class Solution {
public:
    /**
     * @param n: An integer
     * @param edges: a list of undirected edges
     * @return: true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>> &edges) {
        // write your code here

        /**
         * We can use the data structure, disjoint set and union find, to check
         * if a graph is a valid tree. If the graph is a valid tree, it should
         * fulfill the following 2 requirements.
         *
         *  1. Suppose the number of nodes is n, then the number of edges
         *     should be n - 1.
         *
         *  2. The graph has only one connected component.
         */

        if (n == 0) {
            return false;
        }
        if (edges.size() != n - 1) {
            return false;
        }

        DisjointSet sets(n);

        for (const auto& edge : edges) {
            int x = edge[0];
            int y = edge[1];

            if (!sets.merge(x, y)) {
                return false;
            }
        }

        return true;
    }
};
