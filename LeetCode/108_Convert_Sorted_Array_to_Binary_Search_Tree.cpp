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
    TreeNode* sortedArrayToBST(vector<int>& nums) {

        return buildTree(nums, 0, nums.size() - 1);
    }

private:
    TreeNode* buildTree(std::vector<int>& nums, int l, int r) {

        if (l > r) {
            return nullptr;
        }
        if (l == r) {
            return new TreeNode(nums[l]);
        }

        int m = (l + r) / 2;

        auto curr = new TreeNode(nums[m]);
        curr->left = buildTree(nums, l, m - 1);
        curr->right = buildTree(nums, m + 1, r);

        return curr;
    }
};