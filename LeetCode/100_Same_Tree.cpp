/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

        if (!p || !q) {
            return p == q;
        }

        if (!isSameTree(p->left, q->left)) {
            return false;
        }
        if (!isSameTree(p->right, q->right)) {
            return false;
        }

        return (p->val == q->val) ? true : false;
    }
};