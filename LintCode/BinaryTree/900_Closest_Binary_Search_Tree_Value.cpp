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
     * @param root: the given BST
     * @param target: the given target
     * @return: the value in the BST that is closest to the target
     */
    int closestValue(TreeNode * root, double target) {
        // write your code here

        double min_diff = std::numeric_limits<double>::max();
        int ans = -1;
        runBinarySearch(root, target, min_diff, ans);
        return ans;
    }

private:
    void runBinarySearch(
            TreeNode* root,
            double target,
            double& min_diff,
            int& ans) {

        if (!root) {
            return;
        }

        double diff = abs(static_cast<double>(root->val) - target);
        if (diff < min_diff) {
            min_diff = diff;
            ans = root->val;
        }

        if (root->val > target) {
            runBinarySearch(root->left, target, min_diff, ans);
        } else {
            runBinarySearch(root->right, target, min_diff, ans);
        }
    }
};