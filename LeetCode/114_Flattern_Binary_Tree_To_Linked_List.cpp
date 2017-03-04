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
    void flatten(TreeNode* root) {
        if (!root) {
            return;
        }
        traverse(root);
    }

private:
    TreeNode* traverse(TreeNode* current) {
        if (!current->left && !current->right) {
            return current;
        }

        if (current->left && current->right) {
            TreeNode* left_tail = traverse(current->left);
            TreeNode* right_tail = traverse(current->right);

            std::swap(current->left, current->right);

            left_tail->right = current->left;
            current->left = nullptr;
            return right_tail;
        }

        if (current->left) {
            TreeNode* left_tail = traverse(current->left);
            std::swap(current->left, current->right);
            return left_tail;
        }

        return traverse(current->right);
    }
};