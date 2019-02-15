/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode *tree_src, struct TreeNode *tree_tge)
{
    if ((!tree_src) && (!tree_tge))
        return true;
    if ((!tree_src) || (!tree_tge))
        return false;
    if (tree_src->val != tree_tge->val)
        return false;

    bool same_left = isSameTree(tree_src->left, tree_tge->left);
    if (!same_left)
        return false;
    return isSameTree(tree_src->right, tree_tge->right);
}