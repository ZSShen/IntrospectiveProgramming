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

struct Record {
    int sum;
    int max;
    TreeNode* root;

    Record()
      : sum(0),
        max(0),
        root(nullptr)
    { }

    Record(int sum, int max, TreeNode* root)
      : sum(sum),
        max(max),
        root(root)
    { }
};


class Solution {
public:
    /**
     * @param root: the root of binary tree
     * @return: the maximum weight node
     */
    TreeNode * findSubtree(TreeNode * root) {
        // write your code here

        auto result = runPostOrder(root);
        return result.root;
    }

private:
    Record runPostOrder(TreeNode* root) {

        if (!root) {
            return Record();
        }

        auto l = runPostOrder(root->left);
        auto r = runPostOrder(root->right);

        int sum = root->val + l.sum + r.sum;

        int opt;
        TreeNode* opt_node;
        if (l.max > r.max) {
            opt = l.max;
            opt_node = l.root;
        } else {
            opt = r.max;
            opt_node = r.root;
        }

        if (sum > opt) {
            opt = sum;
            opt_node = root;
        }

        return Record(sum, opt, opt_node);
    }
};