/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: the root of binary tree
     * @return: the new root
     */
    TreeNode * convertBST(TreeNode * root) {
        // write your code here

        int sum = 0;
        runReverseInorder(root, sum);
        return root;
    }

private:
    void runReverseInorder(TreeNode* root, int& sum) {

        if (!root) {
            return;
        }

        runReverseInorder(root->right, sum);
        root->val += sum;
        sum = root->val;
        runReverseInorder(root->left, sum);
    }
};