/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */


class Solution {
public:
    /*
     * @param node: A undirected graph node
     * @return: A undirected graph node
     */
    UndirectedGraphNode* cloneGraph(UndirectedGraphNode* node) {
        // write your code here

        if (!node) {
            return nullptr;
        }

        std::queue<UndirectedGraphNode*> queue;
        queue.push(node);

        std::unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> map;
        map[node] = new UndirectedGraphNode(node->label);

        while (!queue.empty()) {
            auto origin = queue.front();
            queue.pop();

            auto clone = map[origin];
            for (auto neighbor : origin->neighbors) {
                if (map.count(neighbor) == 0) {
                    map[neighbor] = new UndirectedGraphNode(neighbor->label);
                    queue.push(neighbor);
                }

                clone->neighbors.push_back(map[neighbor]);
            }
        }

        return map[node];
    }
};