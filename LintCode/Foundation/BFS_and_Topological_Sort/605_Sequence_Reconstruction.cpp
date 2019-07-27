class Solution {
public:
    /**
     * @param org: a permutation of the integers from 1 to n
     * @param seqs: a list of sequences
     * @return: true if it can be reconstructed only one or false
     */
    bool sequenceReconstruction(vector<int> &org, vector<vector<int>> &seqs) {
        // write your code here

        std::unordered_map<int, std::vector<int>> graph;
        std::unordered_map<int, int> indegree;
        int size = 0;

        for (const auto& edge : seqs) {

            // Note that each single sequence is not an edge or a pair of nodes.
            int n = edge.size();
            for (int i = 0 ; i < n ; ++i) {
                int src = edge[i];
                size = std::max(size, src);

                if (i < n - 1) {
                    int dst = edge[i + 1];
                    graph[src].push_back(dst);
                    ++indegree[dst];
                }
            }
        }

        std::queue<int> queue;
        int count = 0;
        for (int i = 1 ; i <= size ; ++i) {
            if (indegree.count(i) == 0) {
                queue.push(i);
                ++count;

                // Have multiple candidates for the first node of the order.
                if (count == 2) {
                    return false;
                }
            }
        }

        std::vector<int> order;

        while (!queue.empty()) {
            count = queue.size();

            // Have multiple candidates for a specific level.
            if (count > 1) {
                return false;
            }

            for (int i = 0 ; i < count ; ++i) {

                int src = queue.front();
                queue.pop();

                order.push_back(src);

                for (int dst : graph[src]) {
                    --indegree[dst];

                    if (indegree[dst] == 0) {
                        queue.push(dst);
                    }
                }
            }
        }

        return order == org;
    }
};
