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
    int maxDepth(TreeNode* root) {

        if (!root) {
            return 0;
        }

        if (!root->left && root->right) {
            return maxDepth(root->right) + 1;
        }

        if (root->left && !root->right) {
            return maxDepth(root->left) + 1;
        }

        return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};