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


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct Record {
    TreeNode* node;
    int label;

    Record(TreeNode* node, int label)
      : node(node), label(label)
    { }
};


class Solution {
public:
    bool isCompleteTree(TreeNode* root) {

        // Level-ordered traversal + label counter

        if (!root) {
            return true;
        }

        int count = 0;
        std::queue<Record> queue;
        queue.push(Record(root, 1));

        while (!queue.empty()) {

            int size = queue.size();
            for (int i = 0 ; i < size ; ++i) {
                auto rec = queue.front();
                queue.pop();

                auto node = rec.node;
                int label = rec.label;

                // Check the label order.
                ++count;
                if (count != label) {
                    return false;
                }

                if (node->left) {
                    queue.push(Record(node->left, label * 2));
                }
                if (node->right) {
                    queue.push(Record(node->right, label * 2 + 1));
                }
            }
        }

        return true;
    }
};