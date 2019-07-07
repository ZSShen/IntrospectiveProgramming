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
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int maxDepth(TreeNode * root) {
        // write your code here

        if (!root) {
            return 0;
        }

        return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
    }
};


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
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int maxDepth(TreeNode * root) {
        // write your code here

        // Preorder Traversal + Height Comparison

        if (!root) {
            return 0;
        }

        int ans = std::numeric_limits<int>::min();
        runPreOrder(root, 1, ans);

        return ans;
    }

private:
    void runPreOrder(TreeNode* root, int h, int& ans) {

        if (!root->left && !root->right) {
            ans = std::max(ans, h);
        }

        if (root->left) {
            runPreOrder(root->left, h + 1, ans);
        }
        if (root->right) {
            runPreOrder(root->right, h + 1, ans);
        }
    }
};