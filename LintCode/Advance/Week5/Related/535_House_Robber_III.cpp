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
         * dp[c]: The maximum profits that we can aggregate in the subtree
         *        rooted by c.
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

        int l = 0, ll = 0, lr = 0, r = 0, rr = 0, rl = 0;

        if (root->left) {
            l = runPostOrder(root->left, memo);
            ll = runPostOrder(root->left->left, memo);
            lr = runPostOrder(root->left->right, memo);
        }
        if (root->right) {
            r = runPostOrder(root->right, memo);
            rr = runPostOrder(root->right->right, memo);
            rl = runPostOrder(root->right->left, memo);
        }

        int max = std::max(root->val + ll + lr + rr + rl, l + r);

        memo[root] = max;
        return max;
    }
};