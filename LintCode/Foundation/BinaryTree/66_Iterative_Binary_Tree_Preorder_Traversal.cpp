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
     * @param root: A Tree
     * @return: Preorder in ArrayList which contains node values.
     */
    vector<int> preorderTraversal(TreeNode * root) {
        // write your code here

        if (!root) {
            return {};
        }

        std::vector<int> ans;
        std::stack<TreeNode*> stk;
        stk.push(root);

        while (!stk.empty()) {

            auto curr = stk.top();
            stk.pop();

            ans.push_back(curr->val);

            if (curr->right) {
                stk.push(curr->right);
            }
            if (curr->left) {
                stk.push(curr->left);
            }
        }

        return ans;
    }
};
