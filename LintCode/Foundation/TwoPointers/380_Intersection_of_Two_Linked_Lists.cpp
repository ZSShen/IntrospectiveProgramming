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

        int len_a = 0;
        auto curr = headA;
        while (curr) {
            ++len_a;
            curr = curr->next;
        }

        int len_b = 0;
        curr = headB;
        while (curr) {
            ++len_b;
            curr = curr->next;
        }

        auto src = headA;
        auto dst = headB;
        int diff = abs(len_a - len_b);
        if (len_a > len_b) {
            for (int i = 0 ; i < len_a - len_b ; ++i) {
                src = src->next;
            }
        } else {
            for (int i = 0 ; i < len_b - len_a ; ++i) {
                dst = dst->next;
            }
        }

        while (src != dst) {
            src = src->next;
            dst = dst->next;
        }

        return src;
    }
};