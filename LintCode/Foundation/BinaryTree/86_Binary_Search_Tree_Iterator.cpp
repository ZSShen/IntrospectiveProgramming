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

/*

                  curr: 1, 6, 10, 11, 12
    10            stack: 
   /  \
  1    11
   \    \
    6    12
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