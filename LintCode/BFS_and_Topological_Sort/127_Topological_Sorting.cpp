/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */

class Solution {
public:
    /*
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*>& graph) {
        // write your code here

        //BFS
        /*
        std::unordered_map<DirectedGraphNode*, int> indegs;
        for (auto node : graph) {
            for (auto neighbor : node->neighbors) {
                ++indegs[neighbor];
            }
        }

        std::queue<DirectedGraphNode*> queue;
        for (auto node : graph) {
            if (indegs.count(node) == 0) {
                queue.push(node);
            }
        }

        std::vector<DirectedGraphNode*> ans;
        while (!queue.empty()) {
            auto curr = queue.front();
            queue.pop();

            ans.push_back(curr);

            for (auto neighbor : curr->neighbors) {
                --indegs[neighbor];
                if (indegs[neighbor] == 0) {
                    queue.push(neighbor);
                }
            }
        }

        return ans;
        */

        // DFS
        std::unordered_set<DirectedGraphNode*> set;
        std::stack<DirectedGraphNode*> stack;

        for (auto node : graph) {
            if (set.count(node) == 0) {
                set.insert(node);
                runDfs(node, set, stack);
            }
        }

        std::vector<DirectedGraphNode*> ans;
        while (!stack.empty()) {
            ans.push_back(stack.top());
            stack.pop();
        }

        return ans;
    }

private:
    void runDfs(
            DirectedGraphNode* curr,
            std::unordered_set<DirectedGraphNode*>& set,
            std::stack<DirectedGraphNode*>& stack) {

        for (auto neighbor : curr->neighbors) {
            if (set.count(neighbor) == 0) {
                set.insert(neighbor);
                runDfs(neighbor, set, stack);
            }
        }

        stack.push(curr);
    }
};