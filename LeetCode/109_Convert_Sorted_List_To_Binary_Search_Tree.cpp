/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return runLevelOrder(head, nullptr);
    }

    TreeNode* runLevelOrder(ListNode* begin, ListNode* end) {

        if (begin == end) {
            return nullptr;
        }
        if (begin->next == end) {
            return new TreeNode(begin->val);
        }

        ListNode* fast = begin;
        ListNode* slow = begin;

        while (fast != end && fast->next != end) {
            slow = slow->next;
            fast = fast->next->next;
        }

        TreeNode* root = new TreeNode(slow->val);
        root->left = runLevelOrder(begin, slow);
        root->right = runLevelOrder(slow->next, end);

        return root;
    }
};