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
     * @param graph: a list of Undirected graph node
     * @param values: a hash mapping, <UndirectedGraphNode, (int)value>
     * @param node: an Undirected graph node
     * @param target: An integer
     * @return: a node
     */
     UndirectedGraphNode* searchNode(vector<UndirectedGraphNode*>& graph,
                                    map<UndirectedGraphNode*, int>& values,
                                    UndirectedGraphNode* node,
                                    int target) {
        // write your code here
        if (graph.size() == 1) {
            return (values[node] == target) ? node : nullptr;
        }

        std::unordered_map<UndirectedGraphNode*, int> map;
        for (const auto& pair : values) {
            map.insert(pair);
        }

        std::queue<UndirectedGraphNode*> queue;
        queue.push(node);

        std::unordered_set<UndirectedGraphNode*> visit;
        visit.insert(node);

        while (!queue.empty()) {
            auto curr = queue.front();
            queue.pop();

            for (auto neighbor : curr->neighbors) {
                if (map[neighbor] == target) {
                    return neighbor;
                }
                if (visit.count(neighbor) == 0) {
                    visit.insert(neighbor);
                    queue.push(neighbor);
                }
            }
        }

        return nullptr;
    }
};