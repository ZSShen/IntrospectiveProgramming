/**
 * Definition of ParentTreeNode:
 * class ParentTreeNode {
 * public:
 *     int val;
 *     ParentTreeNode *parent, *left, *right;
 * }
 */


class Solution {
public:
    /*
     * @param root: The root of the tree
     * @param A: node in the tree
     * @param B: node in the tree
     * @return: The lowest common ancestor of A and B
     */
    ParentTreeNode * lowestCommonAncestorII(ParentTreeNode * root, ParentTreeNode * A, ParentTreeNode * B) {
        // write your code here

        std::unordered_set<ParentTreeNode*> set;

        auto curr = A;
        while (curr) {
            set.insert(curr);
            curr = curr->parent;
        }

        curr = B;
        while (curr) {
            if (set.count(curr) == 1) {
                return curr;
            }
            curr = curr->parent;
        }

        return nullptr;
    }
};