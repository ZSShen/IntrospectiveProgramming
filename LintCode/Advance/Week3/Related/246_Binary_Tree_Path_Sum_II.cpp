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
    vector<vector<int>> binaryTreePathSum2(TreeNode * root, int target) {
        // write your code here

        if (!root) {
            return {};
        }

        std::stack<TreeNode*> stk;
        stk.push(root);

        std::vector<int> prefix;
        std::vector<std::vector<int>> ans;

        while (!stk.empty()) {

            auto start = stk.top();
            stk.pop();

            runPreOrder(start, prefix, ans, 0, target);

            if (start->right) {
                stk.push(start->right);
            }
            if (start->left) {
                stk.push(start->left);
            }
        }

        return ans;
    }

private:
    void runPreOrder(
        TreeNode* root, auto& prefix, auto& ans, int sum, int target) {

        sum += root->val;
        prefix.push_back(root->val);

        if (sum == target) {
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