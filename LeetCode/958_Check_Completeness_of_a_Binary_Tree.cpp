/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

enum State {
    Internal = 0,
    Last = 1
};


class Solution {
public:
    bool isCompleteTree(TreeNode* root) {

        if (!root) {
            return true;
        }

        /**
         *  case 1: Internal Node
         *          P
         *         / \
         *        L   R
         *
         *  case 2: Incomplete subtree (early termination)
         *          P
         *         / \
         *            R
         *
         *  case 3: Should be the last internal node
         *          P
         *         / \
         *        L
         *
         *  case 4: The leaf node
         *          P
         */

        std::queue<TreeNode*> queue;
        queue.push(root);

        int state = State::Internal;

        while (!queue.empty()) {
            auto curr = queue.front();
            queue.pop();

            // Case 2 -> non-complete tree
            if (curr->left == nullptr &&
                curr->right != nullptr) {
                return false;
            }

            // Case 4 -> We are ready to finish the traversal.
            if (curr->left == nullptr &&
                curr->right == nullptr) {
                state = State::Last;
                continue;
            }

            // If we already mark the status as "ready for terminiation" and
            // still encounter any internal node, the tree is not complete.
            if (state == State::Last) {
                return false;
            }

            // Case 3 -> We are ready to finish the traversal.
            if (curr->left != nullptr &&
                curr->right == nullptr) {
                state = State::Last;
                queue.push(curr->left);
                continue;
            }

            // Case 4 -> Normal internal node.
            queue.push(curr->left);
            queue.push(curr->right);
        }

        return true;
    }
};