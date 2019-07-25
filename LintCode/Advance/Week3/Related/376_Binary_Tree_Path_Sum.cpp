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
    /*
     * @param root: the root of binary tree
     * @param target: An integer
     * @return: all valid paths
     */
    vector<vector<int>> binaryTreePathSum(TreeNode * root, int target) {
        // write your code here

        if (!root) {
            return {};
        }

        std::vector<int> prefix;
        std::vector<std::vector<int>> ans;

        runPreOrder(root, prefix, ans, 0, target);
        return ans;
    }

private:
    void runPreOrder(
            TreeNode* root, auto& prefix, auto& ans, int sum, int target) {

        sum += root->val;
        prefix.push_back(root->val);

        if (!root->left && !root->right && sum == target) {
            ans.push_back(prefix);
        }

        if (root->left) {
            runPreOrder(root->left, prefix, ans, sum, target);
        }
        if (root->right) {
            runPreOrder(root->right, prefix, ans, sum, target);
        }

        sum -= root->val;
        prefix.pop_back();
    }
};