class Solution {
public:
    /*
     * @param numCourses: a total of n courses
     * @param prerequisites: a list of prerequisite pairs
     * @return: true if can finish all courses or false
     */
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        // write your code here

        std::vector<std::vector<int>> graph(numCourses, std::vector<int>());
        std::vector<int> indegs(numCourses, 0);

        for (const auto& req : prerequisites) {
            int src = req.first;
            int dst = req.second;

            graph[src].push_back(dst);
            ++indegs[dst];
        }

        std::queue<int> queue;
        for (int i = 0 ; i < numCourses ; ++i) {
            if (indegs[i] == 0) {
                queue.push(i);
            }
        }

        std::vector<int> order;
        while (!queue.empty()) {
            auto curr = queue.front();
            queue.pop();

            order.push_back(curr);

            for (auto neighbor : graph[curr]) {
                --indegs[neighbor];
                if (indegs[neighbor] == 0) {
                    queue.push(neighbor);
                }
            }
        }

        return order.size() == numCourses;
    }
};
