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
     * @return: Postorder in ArrayList which contains node values.
     */
    vector<int> postorderTraversal(TreeNode * root) {
        // write your code here

        if (!root) {
            return {};
        }

        std::vector<int> ans;
        std::stack<TreeNode*> stk;
        findSuccessor(root, stk);

        while (!stk.empty()) {

            auto curr = stk.top();
            stk.pop();

            ans.push_back(curr->val);

            if (!stk.empty()) {
                if (stk.top()->left == curr) {
                    findSuccessor(stk.top()->right, stk);
                }
            }
        }

        return ans;
    }

private:
    void findSuccessor(TreeNode* root, std::stack<TreeNode*>& stk) {

        while (root) {
            stk.push(root);

            if (root->left) {
                root = root->left;
            } else {
                root = root->right;
            }
        }
    }
};