/**
 * Definition for Undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */


class DisjointSet {
public:
    DisjointSet(std::vector<UndirectedGraphNode*>& graph) {

        for (auto node : graph) {
            parents[node] = node;
        }
    }

    auto find(auto x) {

        if (x == parents[x]) {
            return x;
        }

        parents[x] = find(parents[x]);
        return parents[x];
    }

    auto unite(auto a, auto b) {

        auto pa = find(a);
        auto pb = find(b);

        if (pa != pb) {
            parents[pa] = pb;
        }
    }

private:
    std::unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> parents;
};


class Solution {
public:
    /*
     * @param nodes: a array of Undirected graph node
     * @return: a connected set of a Undirected graph
     */
    vector<vector<int>> connectedSet(vector<UndirectedGraphNode*> nodes) {
        // write your code here

        DisjointSet set(nodes);

        for (auto src : nodes) {
            for (auto dst : src->neighbors) {
                set.unite(src, dst);
            }
        }

        std::unordered_map<UndirectedGraphNode*,
            std::vector<UndirectedGraphNode*>> groups;
        for (auto node : nodes) {
            auto rep = set.find(node);
            groups[rep].push_back(node);
        }

        std::vector<std::vector<int>> ans;
        for (auto pair : groups) {
            std::vector<int> group;
            for (auto node : pair.second) {
                group.push_back(node->label);
            }
            ans.emplace_back(std::move(group));
        }

        return ans;
    }
};