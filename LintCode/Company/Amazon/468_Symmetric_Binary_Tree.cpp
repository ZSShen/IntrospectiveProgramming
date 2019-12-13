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
     * @param root: the root of binary tree.
     * @return: true if it is a mirror of itself, or false.
     */
    bool isSymmetric(TreeNode * root) {
        // write your code here

        return checkSymmetric(root, root);
    }

private:
    bool checkSymmetric(TreeNode* left, TreeNode* right) {

        if (!left && !right) {
            return true;
        }

        if (!left || !right) {
            return false;
        }

        if (left->val != right->val) {
            return false;
        }

        return checkSymmetric(left->left, right->right) &&
                checkSymmetric(left->right, right->left);
    }
};