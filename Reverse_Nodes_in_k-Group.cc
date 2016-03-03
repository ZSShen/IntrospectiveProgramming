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
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        if (!head)
            return head;
        if (k <= 1)
            return head;

        bool is_first_grp = true;
        ListNode *pred, *curr, *succ;
        ListNode *new_head = head;
        ListNode *pivot = head;
        ListNode *tail = NULL;
        while (true) {
            pred = NULL;
            curr = pivot;

            if (!curr)
                break;

            // Try to reverse the current group.
            int idx = 0;
            while (idx < k) {
                succ = curr->next;
                curr->next = pred;
                pred = curr;
                curr = succ;
                ++idx;

                // If the size of the current group is less than k,
                // Restore the current group.
                if ((idx < k) && (!curr)) {
                    curr = pred;
                    pred = NULL;
                    while (idx > 0) {
                        succ = curr->next;
                        curr->next = pred;
                        pred = curr;
                        curr = succ;
                        --idx;
                    }
                    break;
                }
            }

            // Set the new list head.
            if (is_first_grp) {
                is_first_grp = false;
                new_head = pred;
            }

            // Concate the current group with the previous group.
            if (tail)
                tail->next = pred;
            tail = pivot;

            // Forward to the next group.
            pivot = succ;
        }

        return new_head;
    }
};