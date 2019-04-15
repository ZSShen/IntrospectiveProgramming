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
        
        /**
         *       10
         *     /    \       s: 
         *    5     19      v:
         *   / \   /  \
         *  2  11 -2   6
         *   \
         *    8                 
         */
    
        std::vector<int> ans;
        if (!root) {
            return ans;
        }
        
        std::stack<TreeNode*> stack;
        stack.push(root);

        while (!stack.empty()) {

            // Visit.
            auto top = stack.top();
            stack.pop();
            ans.push_back(top->val);

            // Try to go right.
            if (top->right) {
                stack.push(top->right);
            }
            
            // Try to go left.
            if (top->left) {
                stack.push(top->left);
            }
        }

        return ans;
    }
};