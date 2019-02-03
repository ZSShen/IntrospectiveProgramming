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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        int min = std::min(p->val, q->val);
        int max = std::max(p->val, q->val);

        while (root) {
            if (root->val < min) {
                root = root->right;
                continue;
            }

            if (root->val > max) {
                root = root->left;
                continue;
            }

            break;
        }

        return root;
    }
};