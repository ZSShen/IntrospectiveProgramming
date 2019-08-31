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


class Solution {
public:
    /*
     * @param root: The root of the binary search tree.
     * @param value: Remove the node with given value.
     * @return: The root of the binary search tree after removal.
     */
    TreeNode * removeNode(TreeNode * root, int value) {
        // write your code here

        // Find the target node.
        TreeNode* pred;
        auto curr = root;
        while (curr) {
            if (curr->val == value) {
                break;
            }

            pred = curr;
            if (curr->val > value) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }

        if (!curr) {
            return root;
        }

        // The node we want to remove has 2 children.
        if (curr->left && curr->right) {
            auto res = findSuccessor(root, curr);
            pred = res.first;
            curr->val = res.second->val;
            curr = res.second;
        }

        // The node has no child.
        if (!curr->left && !curr->right) {

            if (curr == root) {
                delete curr;
                return nullptr;
            }

            if (curr == pred->left) {
                pred->left = nullptr;
            } else {
                pred->right = nullptr;
            }

            delete curr;
            return root;
        }

        // The node has only 1 child.
        auto child = (curr->left) ? curr->left : curr->right;

        if (curr == root) {
            delete curr;
            return child;
        }

        if (curr == pred->left) {
            pred->left = child;
        } else {
            pred->right = child;
        }

        delete curr;
        return root;
    }

private:
    std::pair<TreeNode*, TreeNode*> findSuccessor(auto root, auto dst) {

        TreeNode* pred;
        auto succ = dst;

        if (succ->right) {
            pred = succ;
            succ = succ->right;

            while (succ->left) {
                pred = succ;
                succ = succ->left;
            }

            return std::make_pair(pred, succ);
        }

        pred = succ = nullptr;
        auto curr = root;

        while (curr != dst) {
            if (curr->val > dst->val) {
                pred = succ;
                succ = curr;
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }

        return std::make_pair(pred, succ);
    }
};