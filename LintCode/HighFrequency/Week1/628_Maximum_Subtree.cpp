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
      : sum(0), max(0), root(nullptr)
    { }

    Record(int sum, int max, TreeNode* root)
      : sum(sum), max(max), root(root)
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
        TreeNode* opt_root;
        if (l.max > r.max) {
            opt = l.max;
            opt_root = l.root;
        } else {
            opt = r.max;
            opt_root = r.root;
        }

        if (sum > opt) {
            opt = sum;
            opt_root = root;
        }

        return Record(sum, opt, opt_root);
    }
};


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
    int sum;
    TreeNode* root;

    Result()
      : sum(0), root(nullptr)
    { }

    Result(int sum, TreeNode* root)
      : sum(sum), root(root)
    { }
};


class Solution {
public:
    /**
     * @param root: the root of binary tree
     * @return: the root of the maximum subtree
     */
    TreeNode * findSubtree(TreeNode * root) {
        // write your code here

        Result opt(INT_MIN, nullptr);
        runPostOrder(root, opt);
        return opt.root;
    }

private:
    Result runPostOrder(TreeNode* root, Result& opt) {

        if (!root) {
            return Result();
        }

        auto l = runPostOrder(root->left, opt);
        auto r = runPostOrder(root->right, opt);

        int sum = root->val + l.sum + r.sum;
        if (sum > opt.sum) {
            opt.sum = sum;
            opt.root = root;
        }

        return Result(sum, root);
    }
};