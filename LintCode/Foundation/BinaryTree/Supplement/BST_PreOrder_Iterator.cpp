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
    BSTIterator(TreeNode * root) {

        stack.push(root);
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

        auto top = stack.top();
        stack.pop();

        if (top->right) {
            stack.push(top->right);
        }
        if (top->left) {
            stack.push(top->left);
        }

        return top;
    }

private:
    std::stack<TreeNode*> stack;
};
