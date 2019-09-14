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
     * @param root: root of the given tree
     * @return: whether it is a mirror of itself
     */
    bool isSymmetric(TreeNode * root) {
        // Write your code here

        return !root || isSymmetricHelper(root, root);
    }

private:
    bool isSymmetricHelper(TreeNode* left, TreeNode* right) {

        if (!left || !right) {
            return left == right;
        }

        if (left->val != right->val) {
            return false;
        }

        return
            isSymmetricHelper(left->left, right->right) &&
            isSymmetricHelper(left->right, right->left);
    }
};