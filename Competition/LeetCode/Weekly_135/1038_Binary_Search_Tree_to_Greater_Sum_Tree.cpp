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
    TreeNode* bstToGst(TreeNode* root) {

        int sum = 0;
        runReverseInorder(root, sum);

        return root;
    }

private:
    void runReverseInorder(
            TreeNode* root,
            int& sum) {

        if (!root) {
            return;
        }

        runReverseInorder(root->right, sum);

        sum += root->val;
        root->val = sum;

        runReverseInorder(root->left, sum);
    }
};