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
     * @param root: the root of binary tree.
     * @return: An integer
     */
    int maxPathSum2(TreeNode * root) {
        // write your code here

        if (!root) {
            return 0;
        }

        int sum = 0;
        int opt = root->val;
        runPreOrder(root, sum, opt);

        return opt;
    }

private:
    void runPreOrder(TreeNode* root, int& sum, int& opt) {

        sum += root->val;
        opt = std::max(opt, sum);

        if (root->left) {
            runPreOrder(root->left, sum, opt);
        }
        if (root->right) {
            runPreOrder(root->right, sum, opt);
        }

        sum -= root->val;
    }
};