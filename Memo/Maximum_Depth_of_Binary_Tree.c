/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define MAX(a, b)   (((a) > (b))? (a) : (b))

int maxDepth(struct TreeNode* root) {
    if (!root)
        return 0;
    int max_depth_left = maxDepth(root->left);
    int max_depth_right = maxDepth(root->right);
    return MAX(max_depth_left, max_depth_right) + 1;
}