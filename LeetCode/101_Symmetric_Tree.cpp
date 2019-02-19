/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {

        if (!root) {
            return true;
        }
        return runInorderTraversal(root, root);
    }

private:
    bool runInorderTraversal(TreeNode* curr, TreeNode* copy) {

        if (curr->val != copy->val) {
            return false;
        }

        if ((curr->left && !copy->right) ||
            (!curr->left && copy->right) ||
            (curr->right && !copy->left) ||
            (!curr->right && copy->left)) {
            return false;
        }

        if (curr->left &&
            !runInorderTraversal(curr->left, copy->right)) {
            return false;
        }
        if (curr->right &&
            !runInorderTraversal(curr->right, copy->left)) {
            return false;
        }

        return true;
    }
};