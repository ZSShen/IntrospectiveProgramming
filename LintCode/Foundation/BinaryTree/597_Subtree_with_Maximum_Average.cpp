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
    int size;
    TreeNode* max; // Record the root of the subtree that contains the local maximum.
    double avg;

    Result()
        : sum(std::numeric_limits<int>::min()),
          size(0),
          max(nullptr),
          avg(std::numeric_limits<double>::min())
    { }

    Result(int sum, int size, TreeNode* max, double avg)
        : sum(sum), size(size), max(max), avg(avg)
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

        auto result = runPostOrder(root);
        return result.max;
    }

private:
    Result runPostOrder(TreeNode* root) {

        if (!root) {
            return Result();
        }

        auto l = runPostOrder(root->left);
        auto r = runPostOrder(root->right);

        double child_avg;
        TreeNode* child_max;
        if (l.avg >= r.avg) {
            child_avg = l.avg;
            child_max = l.max;
        } else {
            child_avg = r.avg;
            child_max = r.max;
        }

        int curr_sum = root->val;
        int curr_size = 1;
        if (root->left) {
            curr_sum += l.sum;
            curr_size += l.size;
        }
        if (root->right) {
            curr_sum += r.sum;
            curr_size += r.size;
        }

        double curr_avg = static_cast<double>(curr_sum) / curr_size;
        if (curr_avg >= child_avg) {
            return Result(curr_sum, curr_size, root, curr_avg);
        } else {
            return Result(curr_sum, curr_size, child_max, child_avg);
        }
    }
};