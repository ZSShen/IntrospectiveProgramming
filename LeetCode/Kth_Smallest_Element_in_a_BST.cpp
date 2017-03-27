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
    int kthSmallest(TreeNode* root, int k) {
        if (!root) {
            return 0;
        }

        int count = 0;
        int result;
        traverseTree(root, count, k, result);

        return result;
    }

private:
    bool traverseTree(TreeNode* root, int& count, int k, int& result) {
        if (root->left) {
            if (traverseTree(root->left, count, k, result)) {
                return true;
            }
        }

        ++count;
        if (count == k) {
            result = root->val;
            return true;
        }

        if (root->right) {
            if (traverseTree(root->right, count, k, result)) {
                return true;
            } 
        }

        return false;
    }
};