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
    int rob(TreeNode* root)
    {
        unordered_map<TreeNode*, int> memo;
        memo.insert(pair<TreeNode*, int>(nullptr, 0));
        return Trav(root, memo);
    }

private:
    int Trav(TreeNode* root, unordered_map<TreeNode*, int>& memo)
    {
        auto iter = memo.find(root);
        if (iter != memo.end())
            return iter->second;

        int no_select = 0;
        int select = root->val;
        if (root->left) {
            no_select += Trav(root->left, memo);
            select += memo.find(root->left->left)->second;
            select += memo.find(root->left->right)->second;
        }
        if (root->right) {
            no_select += Trav(root->right, memo);
            select += memo.find(root->right->left)->second;
            select += memo.find(root->right->right)->second;
        }

        int ret = max(select, no_select);
        memo.insert(pair<TreeNode*, int>(root, ret));
        return ret;
    }

};