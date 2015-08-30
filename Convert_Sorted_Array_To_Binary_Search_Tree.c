/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* divide_and_conquer(int *arr_num, int idx_l, int idx_r)
{
    struct TreeNode *new_node = (struct TreeNode*)malloc(sizeof(struct TreeNode));

    if (idx_l == idx_r) {
        new_node->val = arr_num[idx_l];
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    }

    int idx_m = (idx_l + idx_r) >> 1;
    if (idx_m > idx_l)
        new_node->left = divide_and_conquer(arr_num, idx_l, idx_m - 1);
    else
        new_node->left = NULL;
    new_node->right = divide_and_conquer(arr_num, idx_m + 1, idx_r);
    new_node->val = arr_num[idx_m];

    return new_node;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize)
{
    if (numsSize == 0)
        return NULL;

    return divide_and_conquer(nums, 0, numsSize - 1);
}