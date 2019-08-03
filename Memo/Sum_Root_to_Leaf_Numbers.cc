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
    int sumNumbers(TreeNode* root)
    {
        if (!root)
            return 0;

        vector<int> nums;
        vector<int> path;
        path.push_back(root->val);
        traverseTree(root, nums, path);
        path.pop_back();

        int sum = 0;
        for (int i = 0 ; i < nums.size() ; ++i)
            sum += nums.at(i);
        return sum;
    }

private:
    void traverseTree(TreeNode* root, vector<int>& nums, vector<int>& path)
    {
        if (!(root->left) && !(root->right)) {
            int base = 1;
            int num = 0;
            for (int i = path.size() - 1 ; i >= 0 ; --i) {
                num += base * path.at(i);
                base *= 10;
            }
            nums.push_back(num);
            return;
        }

        if (root->left) {
            path.push_back(root->left->val);
            traverseTree(root->left, nums, path);
            path.pop_back();
        }
        if (root->right) {
            path.push_back(root->right->val);
            traverseTree(root->right, nums, path);
            path.pop_back();
        }
    }
};