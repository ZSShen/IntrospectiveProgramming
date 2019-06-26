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
     * @return: The maximum amount of money you can rob tonight
     */
    int houseRobber3(TreeNode * root) {
        // write your code here

        /**
         *        A
         *       / \
         *     B     C
         *    / \   / \
         *   D   E F   G
         *
         * dp[c]: The max number of money the robber can rob in the subtree
         *           rooted by c.
         *
         * dp[c] = MAX | c->val + dp[c->l->l] + dp[c->l->r] + dp[c->r->r] + dp[c->r->l]
         *             | dp[c->l] + dp[c->r]
         */

        std::unordered_map<TreeNode*, int> memo;
        return runPostOrder(root, memo);
    }

private:
    int runPostOrder(TreeNode* root, std::unordered_map<TreeNode*, int>& memo) {

        if (!root) {
            return 0;
        }

        if (memo.count(root) == 1) {
            return memo[root];
        }

        int ll = (root->left)? runPostOrder(root->left->left, memo) : 0;
        int lr = (root->left)? runPostOrder(root->left->right, memo) : 0;
        int rr = (root->right)? runPostOrder(root->right->right, memo) : 0;
        int rl = (root->right)? runPostOrder(root->right->left, memo) : 0;

        int max = std::max(
            root->val + ll + lr + rr + rl,
            runPostOrder(root->left, memo) + runPostOrder(root->right, memo));

        memo[root] = max;
        return max;
    }
};
