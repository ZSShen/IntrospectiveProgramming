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

        std::unordered_set<UndirectedGraphNode*> visit;
        visit.insert(node);

        std::queue<UndirectedGraphNode*> queue;
        queue.push(node);

        auto init = new UndirectedGraphNode(node->label);
        std::unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> map;
        map[node] = init;

        while (!queue.empty()) {
            auto src_curr = queue.front();
            queue.pop();
            auto dst_curr = map[src_curr];

            for (auto src_neighbor : src_curr->neighbors) {
                if (visit.count(src_neighbor) != 1) {
                    visit.insert(src_neighbor);
                    queue.push(src_neighbor);
                    map[src_neighbor] =
                        new UndirectedGraphNode(src_neighbor->label);
                }

                auto dst_neighbor = map[src_neighbor];
                dst_curr->neighbors.push_back(dst_neighbor);
            }
        }

        return init;
    }
};