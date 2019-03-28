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

struct Result {
    int max;
    int min;
    bool is_bst;

    Result(bool is_bst)
        : max(std::numeric_limits<int>::min()),
          min(std::numeric_limits<int>::max()),
          is_bst(is_bst)
    { }

    Result(int max, int min, bool is_bst)
        : max(max), min(min), is_bst(is_bst)
    { }
};


class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode * root) {
        // write your code here

        auto result = runPostOrder(root);
        return result.is_bst;
    }

private:
    Result runPostOrder(TreeNode* root) {

        if (!root) {
            return Result(true);
        }

        if (!root->left && !root->right) {
            return Result(root->val, root->val, true);
        }

        auto l = runPostOrder(root->left);
        auto r = runPostOrder(root->right);

        if (!l.is_bst || !r.is_bst) {
            return Result(false);
        }

        if (!root->left && root->val < r.min) {
            return Result(r.max, root->val, true);
        }

        if (!root->right && root->val > l.max) {
            return Result(root->val, l.min, true);
        }

        if (root->val > l.max && root->val < r.min) {
            return Result(r.max, l.min, true);
        }

        return Result(false);
    }
};
