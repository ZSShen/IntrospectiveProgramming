/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define MAX(a, b)       (((a) > (b))? (a) : (b))


int traverse_post_order(struct TreeNode *root, bool *p_is_bal)
{
    if (!root)
        return 0;

    int height_left = traverse_post_order(root->left, p_is_bal);
    int height_right = traverse_post_order(root->right, p_is_bal);
    if (abs(height_left - height_right) > 1)
        *p_is_bal = false;

    return MAX(height_left, height_right) + 1;
}


bool isBalanced(struct TreeNode* root) {
    bool is_bal = true;
    traverse_post_order(root, &is_bal);
    return is_bal;
}