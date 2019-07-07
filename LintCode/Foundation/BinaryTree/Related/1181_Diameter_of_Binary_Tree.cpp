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
     * @param root: a root of binary tree
     * @return: return a integer
     */
    int diameterOfBinaryTree(TreeNode * root) {
        // write your code here

        /**
         *  Postorder Traversal + Divide and Conquer
         *
         *  To get the diameter of the subtree rooted by a node R, we can divide
         *  the diamter into 2 segments, each of which can be calculated from
         *  either the left branch or the right branch of R. Then, we merge
         *  these 2 segments to form the diameter. Please note that the segment
         *  is essentially the maximum depth of a tree. Therefore, we collect
         *  the maximum depths from both branches and combine them to form
         *  a diameter path.
         */

        int ans = std::numeric_limits<int>::min();
        runPostOrder(root, ans);

        return ans;
    }

private:
    int runPostOrder(TreeNode* root, int& ans) {

        if (!root) {
            return 0;
        }
        if (!root->left && !root->right) {
            return 1;
        }

        int l = runPostOrder(root->left, ans);
        int r = runPostOrder(root->right, ans);

        ans = std::max(ans, r + l);

        return std::max(l, r) + 1;
    }
};