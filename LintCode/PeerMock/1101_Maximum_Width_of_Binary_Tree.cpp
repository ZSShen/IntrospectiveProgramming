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
    TreeNode* node;
    int id;

    Record(TreeNode* node, int id)
      : node(node), id(id)
    { }
};


class Solution {
public:
    /**
     * @param root: the root
     * @return: the maximum width of the given tree
     */
    int widthOfBinaryTree(TreeNode * root) {
        // Write your code here

        std::queue<Record> queue;
        queue.push(Record(root, 1));

        int ans = 0;

        while (!queue.empty()) {

            int size = queue.size();

            /**
             * Handle the potential integer overflow issue by reseting node id.
             *     a
             *    / \         b
             *   b      =>   / \
             *  / \         c   d
             * c   d
             */
            if (size == 1) {
                auto front = queue.front();
                queue.pop();

                auto node = front.node;
                if (node->left) {
                    queue.push(Record(node->left, 2));
                }
                if (node->right) {
                    queue.push(Record(node->right, 3));
                }

                ans = std::max(ans, 1);
                continue;
            }

            int first = 0, last = 0;
            for (int i = 0 ; i < size ; ++i) {
                auto front = queue.front();
                queue.pop();

                auto node = front.node;
                auto id = front.id;

                if (i == 0) {
                    first = id;
                } else if (i == size - 1) {
                    last = id;
                }

                if (node->left) {
                    queue.push(Record(node->left, id << 1));
                }
                if (node->right) {
                    queue.push(Record(node->right, (id << 1) + 1));
                }
            }

            int width = last - first + 1;
            ans = std::max(ans, width);
        }

        return ans;
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


struct Record {
    TreeNode* node;
    int label;

    Record(TreeNode* node, int label)
      : node(node), label(label)
    { }
};


class Solution {
public:
    /**
     * @param root: the root
     * @return: the maximum width of the given tree
     */
    int widthOfBinaryTree(TreeNode * root) {
        // Write your code here

        // Level Order Traversal + Tree Label

        if (!root) {
            return 0;
        }

        int width = 0;

        std::queue<Record> queue;
        queue.push(Record(root, 1));

        while (!queue.empty()) {

            int max = INT_MIN;
            int min = INT_MAX;
            int size = queue.size();

            for (int i = 0 ; i < size ; ++i) {
                auto rec = queue.front();
                queue.pop();

                auto node = rec.node;
                int label = rec.label;

                max = std::max(max, label);
                min = std::min(min, label);

                if (node->left) {
                    queue.push(Record(node->left, label * 2));
                }
                if (node->right) {
                    queue.push(Record(node->right, label * 2 + 1));
                }
            }

            width = std::max(width, max - min + 1);
        }

        return width;
    }
};