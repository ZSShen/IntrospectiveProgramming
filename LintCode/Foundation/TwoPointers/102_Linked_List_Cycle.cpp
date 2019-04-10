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
     * @return: True if it has a cycle, or false
     */
    bool hasCycle(ListNode * head) {
        // write your code here

        if (!head) {
            return false;
        }

        auto slow = head;
        auto fast = slow->next;

        while (slow && fast) {
            if (slow == fast) {
                return true;
            }

            slow = slow->next;
            fast = fast->next;
            if (fast) {
                fast = fast->next;
            }
        }

        return false;
    }
};