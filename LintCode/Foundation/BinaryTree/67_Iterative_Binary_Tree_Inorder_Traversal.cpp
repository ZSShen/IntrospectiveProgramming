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
     * @return: Inorder in ArrayList which contains node values.
     */
    vector<int> inorderTraversal(TreeNode * root) {
        // write your code here

        std::vector<int> ans;
        
        std::stack<TreeNode*> stack;
        TreeNode *cur = root;

        /**                c:
         *       10        s: 
         *      /  \       v:
         *     4    12
         *    / \
         *   1   6
         */

        while (cur || !stack.empty()) {
            
            // Go left.
            while (cur) {
                stack.push(cur);
                cur = cur->left;
            }

            // Visit.
            auto top = stack.top();
            stack.pop();
            cur = top;
            ans.push_back(top->val);
            
            // Go right.
            cur = cur->right;
        }    
        
        return ans;
    }
};