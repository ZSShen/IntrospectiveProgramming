/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */


class DisjointSet {
public:
    DisjointSet(std::vector<DirectedGraphNode*>& graph) {

        for (auto node : graph) {
            parents[node] = node;
        }
    }

    auto find(auto x) {

        if (parents[x] == x) {
            return x;
        }

        parents[x] = find(parents[x]);
        return parents[x];
    }

    void unite(auto a, auto b) {

        auto pa = find(a);
        auto pb = find(b);

        if (pa != pb) {
            parents[pa] = pb;
        }
    }

private:
    std::unordered_map<DirectedGraphNode*, DirectedGraphNode*> parents;
};


class Solution {
public:
    /*
     * @param nodes: a array of Directed graph node
     * @return: a connected set of a directed graph
     */
    vector<vector<int>> connectedSet2(vector<DirectedGraphNode*> nodes) {
        // write your code here

        DisjointSet set(nodes);

        for (auto src : nodes) {
            for (auto dst : src->neighbors) {
                set.unite(src, dst);
            }
        }

        std::unordered_map<
            DirectedGraphNode*, std::vector<int>> map;
        for (auto node : nodes) {
            auto id = set.find(node);
            map[id].push_back(node->label);
        }

        std::vector<std::vector<int>> ans;
        for (auto&& pair : map) {
            ans.emplace_back(std::move(pair.second));
        }

        return ans;
    }
};