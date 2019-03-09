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
     * @param k: the given k
     * @return: the kth smallest element in BST
     */
    int kthSmallest(TreeNode * root, int k) {
        // write your code here

        int counter = 0;
        int ans = 0;
        runInorder(root, counter, k , ans);
        return ans;
    }

private:
    void runInorder(TreeNode* root, int& counter, int k, int& ans) {

        if (!root) {
            return;
        }

        runInorder(root->left, counter, k, ans);
        ++counter;
        if (counter == k) {
            ans = root->val;
        }

        if (counter < k) {
            runInorder(root->right, counter, k, ans);
        }
    }
};