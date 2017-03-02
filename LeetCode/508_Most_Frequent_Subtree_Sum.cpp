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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        std::unordered_map<int, int> bag;
        int maxFreq = 0;

        postOrder(root, bag, maxFreq);

        std::vector<int> ans;
        for (const auto& pair : bag) {
            if (pair.second == maxFreq) {
                ans.push_back(pair.first);
            }
        }

        return ans;
    }

private:
    int postOrder(TreeNode* root, std::unordered_map<int, int>& bag, int& maxFreq) {
        if (!root) {
            return 0;
        }

        int leftSum = postOrder(root->left, bag, maxFreq);
        int rghtSum = postOrder(root->right, bag, maxFreq);

        int treeSum = root->val + leftSum + rghtSum;
        ++bag[treeSum];
        if (bag[treeSum] > maxFreq) {
            maxFreq = bag[treeSum];
        }

        return treeSum;
    }
};