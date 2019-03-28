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
    double diff;
    int value;

    Record(double diff, int value)
        : diff(diff), value(value)
    { }
};


struct RecordComparator {

    bool operator() (const Record& rhs, const Record& lhs) {
        return rhs.diff > lhs.diff;
    }
};


class Solution {
public:
    /**
     * @param root: the given BST
     * @param target: the given target
     * @param k: the given k
     * @return: k values in the BST that are closest to the target
     */
    vector<int> closestKValues(TreeNode * root, double target, int k) {
        // write your code here

        std::priority_queue<Record, std::vector<Record>, RecordComparator> queue;
        traverseTree(root, target, queue);

        std::vector<int> ans;
        for (int i = 0 ; i < k ; ++i) {
            auto rec = queue.top();
            queue.pop();
            ans.push_back(rec.value);
        }

        return ans;
    }

private:
    void traverseTree(
            TreeNode* root,
            double target,
            std::priority_queue<
                Record, std::vector<Record>, RecordComparator>& queue) {

        if (!root) {
            return;
        }

        queue.push(
            Record(abs(static_cast<double>(root->val) - target), root->val));

        traverseTree(root->left, target, queue);
        traverseTree(root->right, target, queue);
    }
};