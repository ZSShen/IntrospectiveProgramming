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
    int maxAncestorDiff(TreeNode* root) {
        
        int opt = std::numeric_limits<int>::min();
        std::vector<int> prefix;
        
        runPreOrder(root, prefix, opt);
        return opt;
    }

private:
    void runPreOrder(TreeNode* root, std::vector<int>& prefix, int& opt) {
        
        if (!root) {
            return;
        }

        for (int num : prefix) {
            int diff = std::abs(num - root->val);
            opt = std::max(opt, diff);
        }
        
        prefix.push_back(root->val);
        
        if (root->left) {
            runPreOrder(root->left, prefix, opt);
        }
        if (root->right) {
            runPreOrder(root->right, prefix, opt);
        }

        prefix.pop_back();
    }
};