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
        
        // Initial construction.
        std::stack<TreeNode*> stack;
        findSucessor(root, stack);

        std::vector<int> ans;
        while (!stack.empty()) {
            auto curr = stack.top();
            stack.pop();
            ans.push_back(curr->val);
            
            if (!stack.empty()) {
                auto parent = stack.top();
                if (parent->left == curr) {
                    findSucessor(parent->right, stack);
                }
            }
        }

        return ans;        
    }

private:
    void findSucessor(TreeNode* root, std::stack<TreeNode*>& stack) {
        
        while (root) {
            stack.push(root);
            
            if (root->left) {
                root = root->left;
            } else {
                root = root->right;
            }
        }
    }
};