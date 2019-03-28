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
private:
    std::stack<TreeNode*> stack;
    TreeNode* curr;

public:
    /*
    * @param root: The root of binary tree.
    */BSTIterator(TreeNode * root)
        : curr(root)
    { }

    /*
     * @return: True if there has next node, or false
     */
    bool hasNext() {
        // write your code here
        return (!curr && stack.empty()) ? false : true;
    }

    /*
     * @return: return next node
     */
    TreeNode * next() {
        // write your code here

        while (curr) {
            stack.push(curr);
            curr = curr->left;
        }

        auto ret = stack.top();
        stack.pop();

        curr = ret->right;
        return ret;
    }
};