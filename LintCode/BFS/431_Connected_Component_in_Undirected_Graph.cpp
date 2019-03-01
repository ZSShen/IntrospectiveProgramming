/**
 * Definition for Undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */


class Solution {
public:
    /*
     * @param nodes: a array of Undirected graph node
     * @return: a connected set of a Undirected graph
     */
    vector<vector<int>> connectedSet(vector<UndirectedGraphNode*> nodes) {
        // write your code here

        std::unordered_set<UndirectedGraphNode*> visit;
        std::vector<std::vector<int>> ans;

        for (auto node : nodes) {
            if (visit.count(node) == 0) {
                ans.push_back(runBfs(node, nodes, visit));
            }
        }

        return ans;
    }


private:
    std::vector<int> runBfs(
            UndirectedGraphNode* start,
            std::vector<UndirectedGraphNode*>& graph,
            std::unordered_set<UndirectedGraphNode*>& visit) {

        std::vector<int> collect;

        std::queue<UndirectedGraphNode*> queue;
        queue.push(start);
        visit.insert(start);

        while (!queue.empty()) {
            auto curr = queue.front();
            queue.pop();

            collect.push_back(curr->label);

            for (auto neighbor : curr->neighbors) {
                if (visit.count(neighbor) == 0) {
                    queue.push(neighbor);
                    visit.insert(neighbor);
                }
            }
        }

        std::sort(collect.begin(), collect.end());
        return collect;
    }
};