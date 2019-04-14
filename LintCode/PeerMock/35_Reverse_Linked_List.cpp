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
     * @param node: a list node in the list
     * @param x: An integer
     * @return: the inserted new list node
     */
    ListNode * insert(ListNode * node, int x) {
        // write your code here
        
        if (!node) {
            auto new_node = new ListNode(x);
            new_node->next = new_node;
            return new_node;
        }

        ListNode* pred = nullptr;
        ListNode* curr = node;
        do {
            pred = curr;
            curr = curr->next;
            
            // At the ascending slope.
            if (pred->val <= x && x <= curr->val) {
                break;
            }
            // At the peak or the bottom.
            if (pred->val > curr->val && (x >= pred->val || x <= curr->val)) {
                break;
            }
        } while (curr != node);

        auto new_node = new ListNode(x);
        pred->next = new_node;
        new_node->next = curr;
        
        return node;
    }
};