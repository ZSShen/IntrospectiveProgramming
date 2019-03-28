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


class Solution {
public:
    /*
     * @param root: The root of the binary search tree.
     * @param node: insert this node into the binary search tree
     * @return: The root of the new binary search tree.
     */
    TreeNode * insertNode(TreeNode * root, TreeNode * node) {
        // write your code here

        TreeNode* parent = nullptr;
        auto curr = root;
        while (curr) {
            parent = curr;
            if (node->val < curr->val) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }

        // For an empty tree.
        if (!parent) {
            return new TreeNode(node->val);
        }

        if (node->val < parent->val) {
            parent->left = new TreeNode(node->val);
        } else {
            parent->right = new TreeNode(node->val);
        }

        return root;
    }
};