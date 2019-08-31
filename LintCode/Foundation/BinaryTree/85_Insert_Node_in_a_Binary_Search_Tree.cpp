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

        if (!root) {
            return node;
        }

        auto curr = root;
        auto pred = root;
        while (curr) {
            pred = curr;
            if (curr->val > node->val) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }

        if (node->val > pred->val) {
            pred->right = node;
        } else {
            pred->left = node;
        }

        return root;
    }
};