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
     * @param root: the given BST
     * @param p: the given node
     * @return: the in-order predecessor of the given node in the BST
     */
    TreeNode * inorderPredecessor(TreeNode * root, TreeNode * p) {
        // write your code here
        
        /**
         *  Case 1
         *      a
         *     /      
         *    / \ 
         *   /___\  
         *        \
         *         b
         * 
         *   Case 2
         *      /\
         *     /  \
         *    /____\    
         *   / 
         *  b
         *   \
         *    a
         */
         
        if (!root || !p) {
            return nullptr;
        }
        
        if (p->left) {
            // Case 1.
            
            p = p->left;
            while (p->right) {
                p = p->right;
            }
            
            return p;
        }
        
        TreeNode* turn = nullptr;
        auto curr = root;
        while (curr != p) {
            if (p->val > curr->val) {
                turn = curr;
                curr = curr->right;
            } else {
                curr = curr->left;
            }
        }
        
        return turn;
    }
};