class Solution {
public:
    /*
     * @param numCourses: a total of n courses
     * @param prerequisites: a list of prerequisite pairs
     * @return: true if can finish all courses or false
     */
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        // write your code here

        std::unordered_map<int, std::vector<int>> graph;
        std::unordered_map<int, int> indegree;

        for (const auto& pair : prerequisites) {
            int src = pair.first;
            int dst = pair.second;

            graph[src].push_back(dst);
            ++indegree[dst];
        }

        std::queue<int> queue;
        for (int i = 0 ; i < numCourses ; ++i) {
            if (indegree.count(i) == 0) {
                queue.push(i);
            }
        }

        std::vector<int> order;
        while (!queue.empty()) {
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

        return order.size() == numCourses;
    }
};