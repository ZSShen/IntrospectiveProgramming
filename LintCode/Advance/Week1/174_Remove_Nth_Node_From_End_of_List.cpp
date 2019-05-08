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
     * @param head: The first node of linked list.
     * @param n: An integer
     * @return: The head of linked list.
     */
    ListNode * removeNthFromEnd(ListNode * head, int n) {
        // write your code here

        /**
         *                 l
         *                      r
         *  1 -> 2 -> 3 -> 4 -> 5 -> null
         *
         */

        if (n == 0) {
            return head;
        }

        auto dummy = new ListNode(-1);
        dummy->next = head;

        auto pred = dummy;
        auto l = head;
        auto r = head;

        for (int i = 0 ; i < n - 1 ; ++i) {
            r = r->next;
        }

        while (r->next) {
            pred = pred->next;
            l = l->next;
            r = r->next;
        }

        pred->next = l->next;
        if (pred == dummy) {
            head = l->next;
        }
        delete l;
        delete dummy;

        return head;
    }
};