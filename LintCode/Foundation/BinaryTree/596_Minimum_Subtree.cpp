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
    TreeNode* root;
    int sum;

    Result()
        : root(nullptr), sum(INT_MAX)
    { }
};


class Solution {
public:
    /**
     * @param root: the root of binary tree
     * @return: the root of the minimum subtree
     */
    TreeNode * findSubtree(TreeNode * root) {
        // write your code here

        Result ans;
        runPostOrder(root, ans);
        return ans.root;
    }

private:
    int runPostOrder(TreeNode* root, Result& ans) {

        if (!root) {
            return 0;
        }

        auto sum = runPostOrder(root->left, ans) +
                   runPostOrder(root->right, ans) +
                   root->val;

        if (sum < ans.sum) {
            ans.sum = sum;
            ans.root = root;
        }

        return sum;
    }
};