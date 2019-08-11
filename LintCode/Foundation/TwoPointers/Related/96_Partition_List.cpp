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
     * @param head: The first node of linked list
     * @param x: An integer
     * @return: A ListNode
     */
    ListNode * partition(ListNode * head, int x) {
        // write your code here

        /**
         *       cl        pr   cr
         *        |         |    |
         *        v         v    v
         *   d -> 1 -> 4 -> 3 -> 2 -> 5 -> 2 ->
         *
         *   Changes:
         *   pr->next = cr->next  (3 -> 5)
         *   cl->next = cr        (1 -> 2)
         *   cr->next = cl->next  (2 -> 4)
         */

        auto dummy = new ListNode(-1);
        dummy->next = head;

        auto cl = dummy;
        while (cl->next && cl->next->val < x) {
            cl = cl->next;
        }

        auto pr = cl;
        auto cr = cl->next;
        while (cr) {
            if (cr->val < x) {
                auto succ = cr->next;

                pr->next = succ;
                cr->next = cl->next;
                cl->next = cr;

                cl = cr;
                cr = succ;
            } else {
                pr = cr;
                cr = cr->next;
            }
        }

        auto new_head = dummy->next;
        delete dummy;
        return new_head;
    }
};