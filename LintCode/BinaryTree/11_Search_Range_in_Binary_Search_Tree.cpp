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
     * @param root: param root: The root of the binary search tree
     * @param k1: An integer
     * @param k2: An integer
     * @return: return: Return all keys that k1<=key<=k2 in ascending order
     */
    vector<int> searchRange(TreeNode * root, int k1, int k2) {
        // write your code here

        std::vector<int> ans;
        traverseTree(root, k1, k2, ans);
        return ans;
    }

private:
    void traverseTree(TreeNode* root, int k1, int k2, std::vector<int>& ans) {

        if (!root) {
            return;
        }

        traverseTree(root->left, k1, k2, ans);

        if (k1 <= root->val && root->val <= k2) {
            ans.push_back(root->val);
        }

        traverseTree(root->right, k1, k2, ans);
    }
};