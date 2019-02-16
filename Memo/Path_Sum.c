/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool traverse_post_order(struct TreeNode *curr, int sum, int *path)
{
    if (!(curr->left) && !(curr->right)) {
        if ((*path + curr->val) == sum)
            return true;
    }

    *path += curr->val;

    bool res_left = false;
    if (curr->left)
        res_left = traverse_post_order(curr->left, sum, path);

    bool res_right = false;
    if (!res_left && (curr->right))
        res_right = traverse_post_order(curr->right, sum, path);

    *path -= curr->val;
    return res_left || res_right;
}

bool hasPathSum(struct TreeNode* root, int sum)
{
    if (!root)
        return false;

    int path = 0;
    return traverse_post_order(root, sum, &path);
}
