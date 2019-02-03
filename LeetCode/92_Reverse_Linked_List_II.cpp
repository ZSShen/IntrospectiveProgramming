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
    ListNode* reverseBetween(ListNode* head, int m, int n) {

        if (!head) {
            return head;
        }
        if (m == n) {
            return head;
        }

        ListNode* pred = nullptr;
        ListNode* curr = head;

        for (int i = 1 ; i < m ; ++i) {
            pred = curr;
            curr = curr->next;
        }

        ListNode* front = pred;
        ListNode* rear = nullptr;
        ListNode* seg_tail = curr;

        pred = nullptr;
        for (int i = m ; i <= n ; ++i) {
            rear = curr->next;
            curr->next = pred;
            pred = curr;
            curr = rear;
        }

        seg_tail->next = rear;

        if (front) {
            front->next = pred;
        } else {
            head = pred;
        }

        return head;
    }
};