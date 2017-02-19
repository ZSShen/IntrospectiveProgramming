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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* merge = nullptr;
        ListNode* head = merge;

        while (l1 && l2) {
            ListNode* cand;
            if (l1->val <= l2->val) {
                cand = l1;
                l1 = l1->next;
            } else {
                cand = l2;
                l2 = l2->next;
            }

            if (!head) {
                head = merge = cand;
            } else {
                merge->next = cand;
                merge = cand;
            }
        }

        if (!l1) {
            if (!head) {
                head = l2;
            } else {
                merge->next = l2;
            }
        }
        if (!l2) {
            if (!head) {
                head = l1;
            } else {
                merge->next = l1;
            }
        }

        return head;
    }
};