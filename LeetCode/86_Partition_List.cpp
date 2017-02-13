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
    ListNode* partition(ListNode* head, int x) {
        ListNode* lessHead = nullptr;
        ListNode* lessTail = nullptr;
        ListNode* greaterHead = nullptr;
        ListNode* greaterTail = nullptr;

        while (head) {
            if (head->val < x) {
                if (!lessHead) {
                    lessHead = head;
                } else {
                    lessTail->next = head;
                }
                lessTail = head;
            } else {
                if (!greaterHead) {
                    greaterHead = head;
                } else {
                    greaterTail->next = head;
                }
                greaterTail = head;
            }
            head = head->next;
        }

        if (lessHead) {
            head = lessHead;
            if (greaterHead) {
                lessTail->next = greaterHead;
                greaterTail->next = nullptr;
            }
        } else if (greaterHead) {
            head = greaterHead;
            greaterTail->next = nullptr;
        }

        return head;
    }
};