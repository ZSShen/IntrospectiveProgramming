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


struct Result {
    int size;
    int sum;
    TreeNode* root;
    
    Result()
        : size(0), sum(0), root(nullptr)
    { }
    
    Result(int size, int sum, TreeNode* root)
        : size(size), sum(sum), root(root)
    { }
};


class Solution {
public:
    /**
     * @param root: the root of binary tree
     * @return: the root of the maximum average of subtree
     */
    TreeNode * findSubtree2(TreeNode * root) {
        // write your code here
        
        Result opt;
        runPostOrder(root, opt);
        return opt.root;
    }

private:
    Result runPostOrder(TreeNode* root, Result& opt) {

        if (!root) {
            return Result();
        }

        auto left = runPostOrder(root->left, opt);
        auto right = runPostOrder(root->right, opt);

        int size = 1 + left.size + right.size;
        int sum = root->val + left.sum + right.sum;
        double avg = static_cast<double>(sum) / size;

        if (!opt.root || avg > static_cast<double>(opt.sum) / opt.size) {
            opt.size = size;
            opt.sum = sum;
            opt.root = root;
        }
        
        return Result(size, sum, root);
    }
};