/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

struct Result {
    TreeNode* node;
    bool found_a;
    bool found_b;

    Result()
        : node(nullptr), found_a(false), found_b(false)
    { }

    Result(TreeNode* node, bool found_a, bool found_b)
        : node(node), found_a(found_a), found_b(found_b)
    { }
};


class Solution {
public:
    /*
     * @param root: The root of the binary tree.
     * @param A: A TreeNode
     * @param B: A TreeNode
     * @return: Return the LCA of the two nodes.
     */
    TreeNode * lowestCommonAncestor3(TreeNode * root, TreeNode * A, TreeNode * B) {
        // write your code here

        auto result = runPostOrder(root, A, B);
        return (result.node && result.found_a && result.found_b) ?
            result.node : nullptr;
    }

private:
    Result runPostOrder(TreeNode* root, TreeNode* A, TreeNode* B) {

        if (!root) {
            return Result();
        }

        auto l = runPostOrder(root->left, A, B);
        auto r = runPostOrder(root->right, A, B);

        bool found_a = l.found_a || r.found_a || root == A;
        bool found_b = l.found_b || r.found_b || root == B;

        if (root == A || root == B)  {
            return Result(root, found_a, found_b);
        }

        if (l.node && r.node) {
            return Result(root, found_a, found_b);
        }

        if (l.node) {
            return Result(l.node, found_a, found_b);
        }
        if (r.node) {
            return Result(r.node, found_a, found_b);
        }

        return Result();
    }
};
