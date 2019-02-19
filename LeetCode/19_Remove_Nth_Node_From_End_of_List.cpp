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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* pred = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast) {
            if (n > 0) {
                --n;
            } else {
                pred = slow;
                slow = slow->next;
            }

            fast = fast->next;
        }

        if (pred) {
            pred->next = slow->next;
            delete slow;
        } else {
            pred = head;
            head = head->next;
            delete pred;
        }

        return head;
    }
};