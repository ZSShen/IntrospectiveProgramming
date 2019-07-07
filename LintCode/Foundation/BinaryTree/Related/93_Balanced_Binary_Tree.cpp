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

struct Record {
    bool balanced;
    int height;

    Record(bool balanced, int height)
      : balanced(balanced), height(height)
    { }
};


class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode * root) {
        // write your code here

        auto res = runPostOrder(root);
        return res.balanced;
    }

private:
    Record runPostOrder(TreeNode* root) {

        if (!root) {
            return Record(true, 0);
        }

        if (!root->left && !root->right) {
            return Record(true, 1);
        }

        auto l = runPostOrder(root->left);
        auto r = runPostOrder(root->right);

        if (!l.balanced || !r.balanced) {
            return Record(false, -1);
        }

        int diff = std::abs(l.height - r.height);
        if (diff > 1) {
            return Record(false, -1);
        }

        return Record(true, std::max(l.height, r.height) + 1);
    }
};