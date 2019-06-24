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
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int maxPathSum(TreeNode * root) {
        // write your code here

        /**
         *      N       1. Consider only the root node. N
         *     / \      2. Consider both subtrees.
         *    /   \         l: The MPS returned from the left subtree.
         *   /\   /\        r: The MPS returned from the right subtree.
         *  /__\ /__\       N + l, N + r, N + l + r.
         */

        int opt = (root) ? root->val : 0;
        runPostOrder(root, opt);
        return opt;
    }

private:
    int runPostOrder(TreeNode* root, int& opt) {

        if (!root) {
            return 0;
        }

        int l = runPostOrder(root->left, opt);
        int r = runPostOrder(root->right, opt);

        int single = std::max(std::max(l, r) + root->val, root->val);
        int full = std::max(single, root->val + l + r);

        opt = std::max(opt, full);
        return single;
    }
};