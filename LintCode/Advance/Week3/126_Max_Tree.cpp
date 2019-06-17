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

        int n = A.size();
        if (n == 0) {
            return nullptr;
        }

        std::vector<TreeNode*> stack;

        for (int i = 0 ; i < n ; ++i) {

            auto node = new TreeNode(A[i]);

            while (!stack.empty() && A[i] > stack.back()->val) {
                node->left = stack.back();
                stack.pop_back();
            }

            if (!stack.empty()) {
                stack.back()->right = node;
            }

            stack.push_back(node);
        }

        return stack[0];
    }
};