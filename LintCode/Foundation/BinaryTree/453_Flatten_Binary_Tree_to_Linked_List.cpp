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
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void flatten(TreeNode * root) {
        // write your code here
        
        /**
         *  case 1: no child
         * 
         *      a     
         * 
         *  case 2: Has a left child
         * 
         *      a    a
         *     /  =>  \ 
         *    b        b  Return b as the last node.
         * 
         *  
         *  case 3: Has a right child
         *   
         *    a      a 
         *     \  =>  \
         *      b      b  Return b as the last node.
         * 
         *  
         *  case 4: Has two children
         * 
         *     a         a      a
         *    / \   =>  /   =>   \
         *   b   c     b          b 
         *              \          \
         *               c          c  Return c as the last node.
         */
         
         runPreOrder(root);
    }
    
private:
    TreeNode* runPreOrder(TreeNode* root) {
        
        if (!root) {
            return nullptr;
        }
        
        auto last_l = runPreOrder(root->left);
        auto last_r = runPreOrder(root->right);

        if (last_l) {
            last_l->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
        
        if (last_r) {
            return last_r;
        }
        
        if (last_l) {
            return last_l;
        }

        return root;
    }

};