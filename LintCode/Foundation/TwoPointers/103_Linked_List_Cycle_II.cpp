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
     * @return: The node where the cycle begins. if there is no cycle, return null
     */
    ListNode * detectCycle(ListNode * head) {
        // write your code here
        
        /*
                                      
                              k - j - i <--- k
                              |       |
                              l       h
                              |       |
              a - b - c - d - e - f - g

            Length of the prefix: X
            Length of the cycle: Y
            2 Pointers meet at the kth node.
              
              t = X + nY + k
             2t = X + mY + k 
           
           => 2X + 2nY + 2k = X + mY + k
           => X + k = (m - 2n)Y

        */
        
        auto slow = head;
        auto fast = head;
        
        while (slow && fast) {
            slow = slow->next;

            fast = fast->next;
            if (fast) {
                fast = fast->next;
            }
            
            if (slow == fast) {
                break;
            }
        }
        
        if (!fast) {
            return nullptr;
        }

        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow;
    }
};
