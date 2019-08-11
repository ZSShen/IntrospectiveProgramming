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
     * @param head: ListNode head is the head of the linked list
     * @param m: An integer
     * @param n: An integer
     * @return: The head of the reversed ListNode
     */
    ListNode * reverseBetween(ListNode * head, int m, int n) {
        // write your code here

        if (!head || m == n) {
            return head;
        }

        // Use the dummy node to simplify the reversing procedure.
        auto dummy = new ListNode(-1);
        dummy->next = head;

        auto pred_bgn = dummy;
        auto curr_bgn = head;

        /**
         *       pb   cb
         *   d -> 1 -> 2 -> 3 -> 4 -> 5
         */
        for (int i = 0 ; i < m - 1 ; ++i) {
            pred_bgn = curr_bgn;
            curr_bgn = curr_bgn->next;
        }

        /**
         *      pb
         *  d -> 1 ->
         *                pe ce
         *    <- 2 <- 3 <- 4  5
         */
        ListNode* pred_end = nullptr;
        auto curr_end = curr_bgn;

        for (int i = m ; i <= n ; ++i) {
            auto succ = curr_end->next;
            curr_end->next = pred_end;
            pred_end = curr_end;
            curr_end = succ;
        }

        // 2 -> 5
        pred_bgn->next->next = curr_end;

        // 1 -> 4
        pred_bgn->next = pred_end;

        // d -> 1 -> 4 -> 3 -> 2 -> 5
        auto new_head = dummy->next;

        delete dummy;
        return new_head;
    }
};