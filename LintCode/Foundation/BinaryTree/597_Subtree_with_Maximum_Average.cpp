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
    int count;
    TreeNode* root;

    Record()
      : sum(0), count(0), root(nullptr)
    { }

    Record(int sum, int count, TreeNode* root)
      : sum(sum), count(count), root(root)
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

        Record opt(INT_MIN, 1, nullptr);
        runPostOrder(root, opt);
        return opt.root;
    }


private:
    Record runPostOrder(TreeNode* root, Record& opt) {

        if (!root) {
            return Record();
        }

        auto l = runPostOrder(root->left, opt);
        auto r = runPostOrder(root->right, opt);

        int sum = l.sum + r.sum + root->val;
        int count = l.count + r.count + 1;

        double test = static_cast<double>(sum) / count;
        double ref = static_cast<double>(opt.sum) / opt.count;
        if (test > ref) {
            opt.sum = sum;
            opt.count = count;
            opt.root = root;
        }

        return Record(sum, count, root);
    }
};