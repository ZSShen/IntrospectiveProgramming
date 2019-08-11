/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */


class Solution {
public:
    /*
     * @param node: the node in the list should be deleted
     * @return: nothing
     */
    void deleteNode(ListNode * node) {
        // write your code here

        if (!node) {
            return;
        }

        auto pred = node;
        auto curr = node;
        auto last = node;

        while (curr->next) {
            curr = curr->next;
            pred->val = curr->val;
            last = pred;
            pred = curr;
        }

        delete curr;
        last->next = nullptr;
    }
};