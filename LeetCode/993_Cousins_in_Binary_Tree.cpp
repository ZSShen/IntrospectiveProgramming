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
    bool isCousins(TreeNode* root, int x, int y) {

        if (!root) {
            return false;
        }

        int x_depth = 0;
        int y_depth = 0;
        TreeNode* x_parent = nullptr;
        TreeNode* y_parent = nullptr;

        runPreorderTraversal(
            nullptr, root, x, y, 0, x_depth, y_depth, x_parent, y_parent);

        return (x_depth == y_depth) && (x_parent != y_parent);
    }

private:
    void runPreorderTraversal(
            TreeNode* parent,
            TreeNode* curr,
            int x, int y,
            int depth,
            int& x_depth, int& y_depth,
            TreeNode*& x_parent, TreeNode*& y_parent) {

        if (curr->val == x) {
            x_parent = parent;
            x_depth = depth;
            return;
        }

        if (curr->val == y) {
            y_parent = parent;
            y_depth = depth;
            return;
        }

        if (curr->left) {
            runPreorderTraversal(
                curr, curr->left, x, y, depth + 1,
                x_depth, y_depth,  x_parent, y_parent);
        }
        if (curr->right) {
            runPreorderTraversal(
                curr, curr->right, x, y, depth + 1,
                x_depth, y_depth, x_parent, y_parent);
        }
    }
};