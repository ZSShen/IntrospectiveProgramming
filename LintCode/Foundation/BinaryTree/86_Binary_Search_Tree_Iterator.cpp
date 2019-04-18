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
 * Example of iterate a tree:
 * BSTIterator iterator = BSTIterator(root);
 * while (iterator.hasNext()) {
 *    TreeNode * node = iterator.next();
 *    do something for node
 */


class BSTIterator {
public:
    /*
    * @param root: The root of binary tree.
    */
    BSTIterator(TreeNode * root) 
      : cur(root)
    { }

    /*
     * @return: True if there has next node, or false
     */
    bool hasNext() {
        // write your code here
        
        return cur || !stack.empty();
    }

    /*
     * @return: return next node
     */
    TreeNode * next() {
        // write your code here
        
        while (cur) {
            stack.push(cur);
            cur = cur->left;
        }

        cur = stack.top();
        stack.pop();
        auto ret = cur;
        cur = cur->right;        
        return ret;
    }

private:
    TreeNode* cur;
    std::stack<TreeNode*> stack;

};


class BSTIterator2 {
public:
    /*
    * @param root: The root of binary tree.
    */BSTIterator(TreeNode * root) {
        // do intialization if necessary
        
        while (root) {
            stack.push(root);
            root = root->left;
        }
    }

    /*
     * @return: True if there has next node, or false
     */
    bool hasNext() {
        // write your code here
        
        return !stack.empty();
    }

    /*
     * @return: return next node
     */
    TreeNode * next() {
        // write your code here
        
        /**
         *       10
         *     /    \       s: 
         *    5     19      v: 
         *   / \   /  \     c:
         *  2  11 -2   6
         *   \
         *    8                 
         */
        
        auto next = stack.top();
        stack.pop();

        auto curr = next->right;
        while (curr) {
            stack.push(curr);
            curr = curr->left;
        }

        return next;    
    }

private:
    std::stack<TreeNode*> stack;
};