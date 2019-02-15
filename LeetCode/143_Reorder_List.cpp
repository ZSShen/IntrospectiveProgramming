/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head) {
            return;
        }
        if (!head->next) {
            return;
        }
        if (!head->next->next) {
            return;
        }

        ListNode* pred = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast) {
            pred = slow;
            slow = slow->next;
            fast = fast->next;
            if (fast) {
                fast = fast->next;
            }
        }

        pred->next = nullptr;
        ListNode* right = reverseList(slow);
        ListNode* left = head;

        while (right) {
            ListNode* left_succ = left->next;
            ListNode* right_succ = right->next;

            left->next = right;
            right->next = left_succ;

            left = left_succ;
            right = right_succ;
        }
    }

private:
    ListNode* reverseList(ListNode* curr) {

        ListNode* pred = nullptr;
        while (curr) {
            ListNode* succ = curr->next;
            curr->next = pred;
            pred = curr;
            curr = succ;
        }

        return pred;
    }
};