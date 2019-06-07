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
     * @param root: The root of binary tree
     * @return: An integer
     */
    int minDepth(TreeNode * root) {
        // write your code here

        if (!root) {
            return 0;
        }

        int ans = std::numeric_limits<int>::max();
        runPreOrder(root, 1, ans);

        return ans;
    }

private:
    void runPreOrder(
            TreeNode* root, int h, int& ans) {

        if (!root->left && !root->right) {
            ans = std::min(h, ans);
            return;
        }

        if (root->left) {
            runPreOrder(root->left, h + 1, ans);
        }
        if (root->right) {
            runPreOrder(root->right, h + 1, ans);
        }
    }
};
