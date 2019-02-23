/**
 * Definition of singly-linked-list:
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param headA: the first list
     * @param headB: the second list
     * @return: a ListNode
     */
    ListNode * getIntersectionNode(ListNode * headA, ListNode * headB) {
        // write your code here

        if (!headA || !headB) {
            return nullptr;
        }

        int len_a = 1;
        ListNode* curr_a = headA;
        while (curr_a->next) {
            curr_a = curr_a->next;
            ++len_a;
        }

        int len_b = 1;
        ListNode* curr_b = headB;
        while (curr_b->next) {
            curr_b = curr_b->next;
            ++len_b;
        }

        if (curr_a != curr_b) {
            return nullptr;
        }

        curr_a = headA;
        curr_b = headB;
        if (len_a > len_b) {
            for (int i = 0 ; i < len_a - len_b ; ++i) {
                curr_a = curr_a->next;
            }
        } else {
            for (int i = 0 ; i < len_b - len_a ; ++i) {
                curr_b = curr_b->next;
            }
        }

        while (curr_a && curr_b && curr_a != curr_b) {
            curr_a = curr_a->next;
            curr_b = curr_b->next;
        }

        return curr_a;
    }
};