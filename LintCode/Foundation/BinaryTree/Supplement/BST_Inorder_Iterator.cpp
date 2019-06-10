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
         *   / \   /  \
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
