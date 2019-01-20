/**
 * Definition for undirected graph.
 * class UndirectedGraphNode {
 *     int label;
 *     List<UndirectedGraphNode> neighbors;
 *     UndirectedGraphNode(int x) { label = x; neighbors = new ArrayList<UndirectedGraphNode>(); }
 * };
 */

public class Solution {
    public UndirectedGraphNode cloneGraph(UndirectedGraphNode node) {

        if (node == null) {
            return null;
        }

        Map<UndirectedGraphNode, UndirectedGraphNode> visit =
            new HashMap<UndirectedGraphNode, UndirectedGraphNode>();

        UndirectedGraphNode root = new UndirectedGraphNode(node.label);
        visit.put(node, root);

        runDFS(node, visit);
        return root;
    }

    private void runDFS(
        UndirectedGraphNode src_curr,
        Map<UndirectedGraphNode, UndirectedGraphNode> visit) {

        UndirectedGraphNode dst_curr = visit.get(src_curr);

        for (UndirectedGraphNode src_neighbor : src_curr.neighbors) {
            UndirectedGraphNode dst_neighbor = visit.get(src_neighbor);

            if (dst_neighbor == null) {
                dst_neighbor = new UndirectedGraphNode(src_neighbor.label);
                visit.put(src_neighbor, dst_neighbor);

                runDFS(src_neighbor, visit);
            }

            dst_curr.neighbors.add(dst_neighbor);
        }
    }
}