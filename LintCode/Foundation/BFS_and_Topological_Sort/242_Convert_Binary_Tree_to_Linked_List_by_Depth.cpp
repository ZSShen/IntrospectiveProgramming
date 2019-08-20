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
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param root the root of binary tree
     * @return a lists of linked list
     */
    vector<ListNode*> binaryTreeToLists(TreeNode* root) {
        // Write your code here

        if (!root) {
            return {};
        }

        std::queue<TreeNode*> queue;
        queue.push(root);

        auto dummy = new ListNode(-1);
        std::vector<ListNode*> ans;

        while (!queue.empty()) {
            int n = queue.size();
            auto pred = dummy;

            for (int i = 0 ; i < n ; ++i) {
                auto node = queue.front();
                queue.pop();

                auto curr = new ListNode(node->val);
                pred->next = curr;
                pred = curr;

                if (node->left) {
                    queue.push(node->left);
                }
                if (node->right) {
                    queue.push(node->right);
                }
            }

            ans.push_back(dummy->next);
        }

        delete dummy;
        return ans;
    }
};