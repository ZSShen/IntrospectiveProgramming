#define MIN(a, b)    ((a < b)? (a) : (b))

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int minDepth(struct TreeNode* root)
{
    if (!root)
        return 0;

    int depth_left = minDepth(root->left);
    int depth_right = minDepth(root->right);

    if (root->left && !(root->right))
        return depth_left + 1;
    else if (!(root->left) && root->right)
        return depth_right + 1;
    return MIN(depth_left, depth_right) + 1;
}