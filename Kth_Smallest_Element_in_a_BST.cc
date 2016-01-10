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
    int kthSmallest(TreeNode* root, int k)
    {
        if (!root)
            return 0;
        vector<int> nums;
        traverseTree(root, nums, k);
        int ans = nums.at(k - 1);
        return ans;
    }

private:
    void traverseTree(TreeNode* root, vector<int>& nums, int k)
    {
        if (root->left)
            traverseTree(root->left, nums, k);
        nums.push_back(root->val);
        if (nums.size() == k)
            return;
        if (root->right)
            traverseTree(root->right, nums, k);
    }
};