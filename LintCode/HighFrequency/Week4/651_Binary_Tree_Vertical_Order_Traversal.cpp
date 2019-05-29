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
    TreeNode* root;
    int level;

    Record(TreeNode* root, int level)
      : root(root),
        level(level)
    { }
};


class Solution {
public:
    /**
     * @param root: the root of tree
     * @return: the vertical order traversal
     */
    vector<vector<int>> verticalOrder(TreeNode * root) {
        // write your code here

        /**
         *     (0)
         *      3
         *     / \
         *(-1)9   20(1)
         *       /  \
         *      15   7
         *     (0)   (2)
         */

        if (!root) {
            return {};
        }

        std::queue<Record> queue;
        queue.push(Record(root, 0));

        std::map<int, std::vector<int>> groups;

        while (!queue.empty()) {

            auto record = queue.front();
            queue.pop();

            auto root = record.root;
            int level = record.level;

            if (root->left) {
                queue.push(Record(root->left, level - 1));
            }
            if (root->right) {
                queue.push(Record(root->right, level + 1));
            }

            groups[level].push_back(root->val);
        }

        std::vector<std::vector<int>> ans;
        for (auto&& pair : groups) {
            ans.emplace_back(std::move(pair.second));
        }

        return ans;
    }
};