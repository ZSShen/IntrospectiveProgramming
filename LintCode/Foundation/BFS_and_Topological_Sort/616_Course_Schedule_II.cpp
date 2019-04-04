class Solution {
public:
    /*
     * @param numCourses: a total of n courses
     * @param prerequisites: a list of prerequisite pairs
     * @return: the course order
     */
    vector<int> findOrder(int numCourses, vector<pair<int, int>> &prerequisites) {
        // write your code here

        std::vector<int> ans;
        if (numCourses == 0) {
            return ans;
        }

        std::unordered_map<int, int> indeg;
        std::vector<std::vector<int>> adj(numCourses, std::vector<int>());
        for (const auto& edge : prerequisites) {
            int src = edge.second;
            int dst = edge.first;
            ++indeg[dst];
            adj[src].push_back(dst);
        }

        std::queue<int> queue;
        for (int i = 0 ; i < numCourses ; ++i) {
            if (indeg.count(i) == 0) {
                queue.push(i);
            }
        }

        while (!queue.empty()) {
            auto src = queue.front();
            queue.pop();

            ans.push_back(src);

            for (int dst : adj[src]) {
                --indeg[dst];
                if (indeg[dst] == 0) {
                    queue.push(dst);
                }
            }
        }

        return (ans.size() == numCourses) ? ans : std::vector<int>();
    }
};