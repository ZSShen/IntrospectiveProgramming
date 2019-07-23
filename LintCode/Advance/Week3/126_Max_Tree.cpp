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
     * @param A: Given an integer array with no duplicates.
     * @return: The root of max tree.
     */
    TreeNode * maxTree(vector<int> &A) {
        // write your code here

        /**
         *  1. If the value stored in the new node is greater than the value
         *     storeed in the previous node (the node on top of the stack),
         *     we need to pop all the nodes from the stack until that we meet
         *     a node contains the greater value or the stack is empty.
         *     Moreover, we need to assign the last poped node as the left
         *     child of this new node.
         *
         *  2. If the value stored in the new node is less than the value
         *     stored in the previous node (the node on top of the stack),
         *     we need to assign this new node as the right child of the
         *     previous node.
         *
         *      2, 5, 6, 0, 3, 1
         *
         *  Stack: 2,
         *         2, 5
         *         5
         *         5, 6
         *         6
         *         6, 0
         *         6, 0, 3
         *         6, 3
         *         6, 3, 1
         *
         *  Tree:
         *
         *      2 =>  5  =>  6  =>  6    =>  6   =>   6
         *           /      /      / \      / \      / \
         *          2      5      5   0    5   3    5   3
         *                /      /        /   /    /   / \
         *               2      2        2   0    2   0   1
         */

        std::vector<TreeNode*> stk;

        for (int num : A) {

            auto curr = new TreeNode(num);

            while (!stk.empty() && num > stk.back()->val) {
                curr->left = stk.back();
                stk.pop_back();
            }

            if (!stk.empty()) {
                stk.back()->right = curr;
            }

            stk.push_back(curr);
        }

        return (!stk.empty()) ? stk[0] : nullptr;
    }
};
