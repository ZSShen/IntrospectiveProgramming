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
    /**
     * @param root: A Tree
     * @return: A list of lists of integer include the zigzag level order traversal of its nodes' values.
     */
    vector<vector<int>> zigzagLevelOrder(TreeNode * root) {
        // write your code here

        /**
         * We can use 2 stacks to control the traversal.
         *
         * In a specific level, we consume all the nodes collected in the first
         * stack and explore the children of those nodes.
         *
         * If the level number is even, e.g. 0 and 2, we explore the children
         * from the very left side to the very right side and push them onto
         * the second stack.
         *
         * If the level number is odd, e.g. 1 and 3, we explore the children
         * from the very right side to the very left side and push them onto
         * the second stack.
         *
         * Upon finishing consuming the nodes collected in the first stack,
         * we override the first stack with the content of the second stack.
         *
         *      Visualization:
         *
         *      ------>-----> level 0  L -> R
         *                  |
         *      <-----<-----| level 1  R -> L
         *      |
         *      |----->-----> level 2  L -> R
         *
         */

        if (!root) {
            return {};
        }

        std::vector<std::vector<int>> ans;

        std::stack<TreeNode*> first;
        first.push(root);

        int level = 0;

        while (!first.empty()) {
            int n = first.size();
            std::stack<TreeNode*> second;
            std::vector<int> collect;

            for (int i = 0 ; i < n ; ++i) {
                auto node = first.top();
                first.pop();

                collect.push_back(node->val);

                if (level % 2 == 0) {
                    if (node->left) {
                        second.push(node->left);
                    }
                    if (node->right) {
                        second.push(node->right);
                    }
                } else {
                    if (node->right) {
                        second.push(node->right);
                    }
                    if (node->left) {
                        second.push(node->left);
                    }
                }
            }

            ans.emplace_back(std::move(collect));
            first = std::move(second);
            ++level;
        }

        return ans;
    }
};
