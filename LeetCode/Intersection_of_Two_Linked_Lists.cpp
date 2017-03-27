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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) {
            return nullptr;
        }

        int lenA = 1;
        ListNode* currA = headA;
        while (currA->next) {
            currA = currA->next;
            ++lenA;
        }

        int lenB = 1;
        ListNode* currB = headB;
        while (currB->next) {
            currB = currB->next;
            ++lenB;
        }

        if (currA != currB) {
            return nullptr;
        }

        currA = headA;
        currB = headB;
        if (lenA > lenB) {
            for (int i = 0 ; i < lenA - lenB ; ++i) {
                currA = currA->next;
            }
        } else {
            for (int i = 0 ; i < lenB - lenA ; ++i) {
                currB = currB->next;
            }
        }

        while (currA != currB) {
            currA = currA->next;
            currB = currB->next;
        }

        return currA;
    }
};
